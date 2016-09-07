/*************************************************************************
	> File Name: lru_cache.h
	> Author: Bryon
	> Mail: chaojinyao@gmail.com 
	> Created Time: Wed 07 Sep 2016 01:47:22 PM CST
 ************************************************************************/
#ifndef HM_LRU_CACHE_H_
#define HM_LRU_CACHE_H_

#include<unordered_map>
#include<list>
#include<string>
#include<cstdef>

namespace cache{

template <typename key_t,typename value_t>
class LruCache{
public:

	using Key_value_pair_t = typename std::pair<key_t,value_t>;
	using List_iterator_t = std::list<key_value_pair_t>::iterator;
	
	LruCache(size_t max_size);
	void put(const key_t &,const value_t);
	const value_t & get(const key_t &);

	bool Exist(const key_t &);
	bool IsFull();
	size_t SizeOfCached();
private:

	std::list<key_value_pair_t> cached_list_;
	std::unordered_map<key_t,value_t> map_item_;
	size_t max_size_;   //the number of cached element 
		
	};

} //namespcae cache

#endif /*HM_LRU_CACHE_H_*/
