#include"lru_cache.h"

namespace cache{

	//initial the size of cache 
	LruCache::LruCache(size_t max_size)
		:max_size_(max_size){}

	//
	void LruCache::put(const key_t& key,const vlaue_t& value)
	{
		auto it = map_item_.find(key);
		//first insert it into the head of list
		cached_list_.push_front(Key_value_pair_t<key,value>);

		if(it == map_item_.end()){
			//the content is not in cache,put <key,iterator of list> into the map
			//if list size is larger than max_size num,
			//delete the map,and list 
			map_item_.insert(std::make_pair(key,cached_list_.begin()));
			if(map_item_.size() > max_size_){
				auto last = cached_list_.end();
				last--;
				map_item_.erase(last->first);
				cached_list_.pop_back();
			}
		} else {
			
			//the content is in the cache,
			//first,delete the cached map<key,iterator>
			cached_list_.erase(it->second);
			map_item_.erase(it);
			map_item_.insert(std::make_pair(key,cached_list_.begin()));
			
		}
	}
	//get the content from the cache
	//condition:the Exist returns true
	const value_t & LruCache::get(const key_t & key)
	{
		auto it = map_item_.find(key);
		//move the cached content to  the head of the list
		cached_list_.splice(cached_list_.begin(),cached_list_,it);
		return  it->second->second;
		
	}
	//check the content is / isn't in the cache
	bool LruCache::Exist(const key_t &key)
	{
		auto it = map_item_.find(key);
		if(it != map_item_.end())
			return true;
		else
			return false;
	}

	//check if the cache is full
	bool LruCache::IsFull()
	{
		if(map_item_.size() == max_size_)
			return true;
		else
			return false;
	}

	size_t LruCache::SizeOfCached()
	{
		return map_item_.size();
	}

}

