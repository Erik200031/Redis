#include "redis.h"

void myl::Redis::lpush(List& lst, String element) 
{
    lst.push_back(element);
}

String myl::Redis::get_l(const List& lst, int index1, int index2) const 
{
    if(index1 > index2) {
        std::cout << "ERROR unknown index";
        return "";
    }
    else {
        int tmp = index1 + index2;
        String ret_value;
        while(tmp) {
            ret_value += lst.get(index1); 
            tmp--;
            index1++;
            ret_value += ' ';
        }
        return ret_value;
    }
}

void myl::Redis::um_push(Unordered_map<String,String>& obj, String key, String value) 
{
    obj.emplace(key,value);
}

String myl::Redis::get_um(Unordered_map<String, String>& ob, const String& key) const
{
    return ob[key];
}

void myl::Redis::clear(Unordered_map<String,String>& ob)
{
    ob.clear();
}

void myl::Redis::push_str(String& str, const String& element) 
{
    str += element;
}

String myl::Redis::get_str(const String& str) const 
{
    return str;
}

