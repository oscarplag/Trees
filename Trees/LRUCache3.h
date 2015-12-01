#pragma once
#include<map>
#include<list>

template<typename K, typename V>
class LRUCache3
{
private:
	int _capacity;
	V (*_fn)(const K& myKey);
	std::map < K, std::pair<V, typename list<K>::iterator>> myMap;
	std::list<V> myList;
	void evict()
	{
		std::map<K, std::pair<V,list<K>::iterator>>::iterator it = myMap.find(myList.front());
		myMap.erase(it);
		myList.pop_front();
	}

public:
	LRUCache3(V(*f)(const K&), int c) : _fn(f), _capacity(c)
	{
	};
	~LRUCache3() {};

	V Insert(const K& myKey)
	{
		std::map<K, std::pair<V, list<K>::iterator>>::iterator it = myMap.find(myKey);

		if (it== myMap.end())
		{
			V val = _fn(myKey);
			if (myMap.size() == _capacity)
				evict();
			std::list<V>::iterator listIt = myList.insert(myList.end(), myKey);
			myMap[myKey] = std::make_pair(val,listIt);
			return val;
		}
		else
		{
			myList.splice(myList.end(), myList, (*it).second.second);
			return(*it).second.first;
		}
	}

	V GetValue(const K& myKey)
	{
		std::map<K, std::pair<V, list<K>::iterator>>::iterator it = myMap.find(myKey);
		if (it != myMap.end())
		{
			std::pair<V, list<K>::iterator> myPair = (*it).second;
			V val = myPair.first;
			myList.splice(myList.end(), myList, myPair.second);
			return val;
		}
		else
			return V(0);
	}
};

