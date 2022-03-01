#ifndef REDIS_H
#define REDIS_H
#include <iostream>
#include "./string/string.h"
#include "./list/list.h"
#include "./unordered_map/Unordered_map.h"
#include "./set/set.h"

namespace myl
{
    class Redis
    {
    public:
        Redis()=default;
        Redis(const Redis&) = delete;
        Redis& operator=(const Redis&) = delete;
        Redis(Redis&&) = delete;
        Redis& operator=(Redis&&) = delete;
        ~Redis()=default;

        void lpush(const String&,const String&);
        String get_list(const String&, int,int);
        void clear_list(const String&);
        void um_push( const String&,const String&,const String&);
        String get_um(const String&, const String&) ;
        void clear_um(const String&);
        void push_str(const String&, const String&);
        String get_str(const String&) ;
        void clear_str(const String&);
        void set_push(const String&,const String&);
        String get_set(const String&);
        void clear_set(const String&);

    private:
        Unordered_map<String, myl::list<String>> m_umsl;
        Unordered_map<String, String> m_umss;
        Unordered_map<String, Unordered_map<String, String>> m_umum; 
        Unordered_map<String, myl::set<String>> m_umst;
    };

} // namespace myl


#include "redis.hpp"


#endif //REDIS_H
