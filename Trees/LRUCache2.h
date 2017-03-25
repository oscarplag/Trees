#pragma once
#include <cassert>
#include <list>
#include <map>

template<typename K,typename V,template<typename...> class MAP> 
class LRUCache2
{
public:

	typedef K key_type;
	typedef V value_type;

	// Key access history, most recent at back
	typedef std::list<key_type> key_tracker_type;

	// Key to value and key history iterator 
	typedef MAP<
		key_type,
		std::pair<
		value_type,
		typename key_tracker_type::iterator
		>
	> key_to_value_type;

	LRUCache2(value_type(*f)(const key_type&), size_t c) : _fn(f), _capacity(c)
	{
		assert(c);
	}
	~LRUCache2() {};

	value_type operator()(const key_type& k)
	{
		// Attempt to find existing record 
		const typename key_to_value_type::iterator it
			= _key_to_value.find(k);

		if (it == _key_to_value.end()) {

			// We don't have it: 

			// Evaluate function and create new record 
			const value_type v = _fn(k);
			insert(k, v);

			// Return the freshly computed value 
			return v;

		}
		else {

			// We do have it: 

			// Update access record by moving 
			// accessed key to back of list 
			_key_tracker.splice(
				_key_tracker.end(),
				_key_tracker,
				(*it).second.second
				);

			// Return the retrieved value 
			return (*it).second.first;
		}
	}


	template <typename IT> void get_keys(IT dst) const
	{
		typename key_tracker_type::const_reverse_iterator src
			= _key_tracker.rbegin();
		while (src != _key_tracker.rend()) {
			?dst++ = ?src++;
		}
	}

private:

	// Record a fresh key-value pair in the cache 
	void insert(const key_type& k, const value_type& v)
	{
		// Method is only called on cache misses 
		assert(_key_to_value.find(k) == _key_to_value.end());

		// Make space if necessary 
		if (_key_to_value.size() == _capacity)
			evict();

		// Record k as most-recently-used key 
		typename key_tracker_type::iterator it
			= _key_tracker.insert(_key_tracker.end(), k);

		// Create the key-value entry, 
		// linked to the usage record. 
		_key_to_value.insert(
			std::make_pair(
				k,
				std::make_pair(v, it)
				)
			);
		// No need to check return, 
		// given previous assert.
	}

	// Purge the least-recently-used element in the cache 
	void evict()
	{
		// Assert method is never called when cache is empty 
		assert(!_key_tracker.empty());

		// Identify least recently used key 
		const typename key_to_value_type::iterator it
			= _key_to_value.find(_key_tracker.front());
		assert(it != _key_to_value.end());

		// Erase both elements to completely purge record 
		_key_to_value.erase(it);
		_key_tracker.pop_front();
	}


	// The function to be cached 
	value_type (*_fn)(const key_type&);

	// Maximum number of key-value pairs to be retained 
	const size_t _capacity;

	// Key access history 
	key_tracker_type _key_tracker;

	// Key-to-value lookup 
	key_to_value_type _key_to_value;
};
