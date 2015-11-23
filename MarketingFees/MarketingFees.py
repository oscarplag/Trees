import json
import sys
import os
from collections import defaultdict
import datetime
import operator

#extract the date that the lease was signed
def GetDateSigned(input):
	return datetime.datetime.strptime(input["lease_signed"],"%Y-%m-%d")

#extract the date the apartment was first seen
def GetDateSeen(input):
	return datetime.datetime.strptime(input["first_seen"],"%Y-%m-%d")

#extract the quarter period from the date
def GetQuarter(date):
	if date < datetime.datetime(date.year,4,1):
		return 1
	elif date < datetime.datetime(date.year,7,1):
		return 2
	elif date < datetime.datetime(date.year,10,1):
		return 3
	else:
		return 4

#print out the list
def printList(tupList):
	i = 0
	year = tupList[0][0]
	quarter = tupList[0][1]
	print(str(year)+ "Q" + str(quarter))
	while i < len(tupList):
		yearNext = tupList[i][0]
		quarterNext = tupList[i][1]	
		if yearNext != year or quarterNext !=quarter:
			print("")
			print(str(yearNext)+" Q" + str(quarterNext) + ":")
			year = yearNext
			quarter = quarterNext
		print("Marketing Source: " + tupList[i][2] + ", Number of apartments seen: " + str(tupList[i][5]) + ", Number of leases signed: " + str(tupList[i][4]) + ", Average lease sign time: " + str(tupList[i][3]) + ", Total cost: $" + str(tupList[i][6]) + ", Average cost per lease: $" + str(tupList[i][7])) 
		i = i +1

#analyze the list
def AnalyzeList(dict):
	tupList= []
	for key in dict:
		#sort by date first seen	
		dictSorted= sorted(dict[key], key=lambda k: k['first_seen'])
		i = 0
		#iterate through all the occurances for the specified key
		while i < len(dictSorted):
			dateSeen = GetDateSeen(dictSorted[i])
			quarter = GetQuarter(dateSeen)
			quarterNext = quarter
			signed = False
			numSigned = 0
			numSeen = 0	
			avgSignTime = 0
			totalRent = 0
			#iterate until the quarter changes
			while(quarterNext == quarter and i<len(dictSorted)):
				dateSeen = GetDateSeen(dictSorted[i])
				#check if a lease was signed
				if dictSorted[i]["lease_signed"]!=None:
					dateSigned = GetDateSigned(dictSorted[i])
					timeToSign = (dateSigned-dateSeen).days
					signed = True
					numSigned = numSigned+1
					avgSignTime = avgSignTime + timeToSign 	
					totalRent = totalRent + dictSorted[i]["resident_rent"]
				numSeen = numSeen+1
				i = i+1
				quarterNext = GetQuarter(dateSeen)

		  	costPerLease = 0	
			totalCost = 0
			source = key
			#based on the marketing source compute the costs
			if source == "apartment guide":
				totalCost = 495*3 #3 months/quarter
			elif source == "craigslist.com":
				totalCost = 0
				costPerLease = 0	
			elif source == "apartments.com":
				totalCost = 295*numSigned
			elif source == "for rent":
				totalCost = 195*3 + 25*numSeen
			elif source == "resident referral":
				totalCost = 500*numSigned
			elif source == "rent.com":
				totalCost = 595 
				if totalCost < (totalRent*0.5):
					totalCost = totalRent*0.5
			if numSigned !=0:
				avgSignTime = avgSignTime/numSigned
				costPerLease = totalCost/numSigned
			tup=(dateSeen.year,quarter,key,avgSignTime,numSigned,numSeen,totalCost,costPerLease)
			tupList.append(tup)

	#sort on year, then quarter, then cost per lead	
	sortedTupList = sorted(tupList,key = lambda x: (x[0],x[1],x[7],x[4]))
	#print out the sorted list
	printList(sortedTupList)

def LoadMarketingData(filename):
	dict= defaultdict(list)

	#make sure the file exists
	if os.path.isfile(filename) == False:
		print("File not found please check path!")
		return -1
	#set to lower case to prevent possible case error with input
	if filename.lower().endswith(".json") == False:
		print("Expecting a \".json\" file!")
		return -1
	#open the file and load in the JSON data
	with open(filename)as data_file:
		data=json.load(data_file)
	
	#add each entry into a dictonary based on the marketing source (use a list to allow multiple entries)
	for i in range(0,len(data)):
		if data[i]["marketing_source"] == None:
			source = "None"
		else:
			source = data[i]["marketing_source"].lower()
		dict[source].append(data[i])
	AnalyzeList(dict)
				
if len(sys.argv) <= 1:
	print("Please provide path to input Marketing data file!");
	sys.exit(0)
LoadMarketingData(sys.argv[1])
