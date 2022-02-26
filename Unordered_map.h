#pragma once
#include <list>
#include <exception>
#include <stdexcept>
#include "string.h"


template<typename Key, typename Val>
struct pair
{
	Key first {};
	Val second {};
	pair() {};
	pair(Key _k, Val _v) :first(_k), second(_v) {};
	void swap(pair<Key, Val>& ob)
	{
		pair<Key, Val>_tmp;
		_tmp.first = first;
		_tmp.second = second;
		first = ob.first;
		second = ob.second;
		ob.first = _tmp.first;
		ob.second = _tmp.second;
	}

};


struct hesh
{
	hesh() = default;
	uint32_t operator()(const String& obj,const uint32_t& tabel_size)const
	{
		uint32_t h = 0, rand_number_1 = 123456, rand_number_2 = 654321;
		for (int32_t i=0; i != obj.size(); ++i)
		{
			h = (rand_number_1 * h + static_cast<int32_t>(obj[i])) % tabel_size;
			rand_number_1 = (rand_number_1 * rand_number_2) % (tabel_size - 1);
		}
		return h < 0 ? h + tabel_size : h;
	}
};



template <typename Key,typename Val,typename Hesh_method=hesh>
class Unordered_map
{
private:
	Hesh_method hesh_str;
	vector<std::list<std::pair<Key, Val>>> obj;
public:
	// Constructors
	Unordered_map() ;
	Unordered_map(const Key& , const Val& );
	Unordered_map(const Unordered_map<Key, Val, Hesh_method>& );
	Unordered_map(Unordered_map<Key, Val, Hesh_method>&& );

	// Operators
	Unordered_map& operator=(const Unordered_map& );
	Unordered_map& operator=(const Unordered_map&& );
	Val& operator[](const Key&);
	// Iterator

	// Member fuctions
	void insert(std::pair<Key, Val>);
	void emplace(const Key&, const Val&);
	void erase(const Key&);
	Val& at(const Key&);
	void clear();


	// Destructor
	~Unordered_map() {};

};


template<typename Key, typename Val,typename Hesh_method >
Unordered_map<Key, Val, Hesh_method>::Unordered_map():obj(500) {};


template<typename Key, typename Val, typename Hesh_method >
Unordered_map<Key, Val, Hesh_method>::Unordered_map(const Key& k, const Val& v):obj(500)
{
	uint32_t index = hesh_str(k, obj.getSize());
	obj[index].push_back(std::make_pair(k, v));
}


template<typename Key, typename Val, typename Hesh_method >
Unordered_map<Key, Val, Hesh_method>::Unordered_map(const Unordered_map<Key, Val, Hesh_method>& other)
{
	this->obj = other.obj;
}


template<typename Key, typename Val, typename Hesh_method >
Unordered_map<Key, Val, Hesh_method>::Unordered_map(Unordered_map<Key, Val, Hesh_method>&& oth) 
{
	this->obj = oth.obj;
}




template<typename Key, typename Val, typename Hesh_method >
Val& Unordered_map<Key, Val, Hesh_method>::operator[](const Key& ki)
{
	uint32_t ind = hesh_str(ki, obj.getSize());
	for (auto it = obj[ind].begin(); it != obj[ind].end(); ++it)
	{
		if (it->first == ki)
			return it->second;
	}
	obj[ind].push_back(std::make_pair(ki, Val()));
	auto itr = obj[ind].begin();
	itr->first = ki;
	return itr->second;

}
 


 template<typename Key, typename Val, typename Hesh_method >
 Unordered_map<Key, Val, Hesh_method>& Unordered_map<Key, Val, Hesh_method>::operator=(const Unordered_map& other)
 {
	 this->obj = other.obj;
	 return *this;
 }


 template<typename Key, typename Val, typename Hesh_method >
 Unordered_map<Key, Val, Hesh_method>& Unordered_map<Key, Val, Hesh_method>::operator=(const Unordered_map&& oth)
 {
	 this->obj = oth.obj;
	 return *this;
 }


 template<typename Key, typename Val, typename Hesh_method >
 void Unordered_map<Key, Val, Hesh_method>::insert(std::pair<Key, Val>ob)
 {
	 uint32_t ind = hesh_str(ob.first, obj.size());
	 obj[ind].push_back(std::make_pair(ob.first, ob.second));
 }


 template<typename Key, typename Val, typename Hesh_method >
 void Unordered_map<Key, Val, Hesh_method>::emplace(const Key& ki, const Val& va)
 {
	 uint32_t ind = hesh_str(ki, obj.getSize());
	 obj[ind].push_back(std::make_pair(ki, va));
 }


 template<typename Key, typename Val, typename Hesh_method >
 void Unordered_map<Key, Val, Hesh_method>::erase(const Key& ki)
 {
	 uint32_t ind = hesh_str(ki, obj.size());
	 for (auto it = obj[ind].cbegin(); it != obj[ind].cend(); ++it)
	 {
		 if (it->first == ki)
		 {
			 obj[ind].erase(it);
			 break;
		 }
	 }
 }


 template<typename Key, typename Val, typename Hesh_method >
 Val& Unordered_map<Key, Val, Hesh_method>::at(const Key& ob)
 {
	 uint32_t ind = hesh_str(ob, obj.size());
	 try
	 {
		 if (!obj[ind].empty())
		 {
			 for (auto it = obj[ind].begin(); it != obj[ind].end(); ++it)
			 {
				 if (it->first == ob)
					 return it->second;
			 }
		 }
		 else
		 {
			 throw std::out_of_range("out of range");
		 }
	 }

	 catch (const std::out_of_range& obe)
	 {
		 obe.what();
		 abort();
	 }
 }




 template<typename Key, typename Val, typename Hesh_method >
 void Unordered_map<Key,Val,Hesh_method>::clear()
 {
	for(int32_t i=0;i<obj.getSize();++i){
		obj[i].clear();
	}
 }