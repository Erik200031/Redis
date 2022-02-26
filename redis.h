#ifndef REDIS_H
#define REDIS_H
#include <iostream>
#include "string.h"
#include "list.h"
#include "Unordered_map.h"

namespace myl
{
    class Redis
    {
    private:
        
    public:
        Redis();
        ~Redis();
    private:
        void lpush(List&, String);
        String get_l(const List&, int, int) const;
        void clear(List&);
        void um_push(Unordered_map<String,String>&, String, String);
        String get_um(Unordered_map<String, String>&, const String&) const;
        void clear(Unordered_map<String,String>&);
        void push_str(String&, const String&);
        String get_str(const String&) const;
    private:
        Unordered_map<String, List> m_umsl;
        Unordered_map<String, String> m_umss;
        Unordered_map<String, Unordered_map<String, String>> m_umum; 
    };

} // namespace myl





#endif //REDIS_H