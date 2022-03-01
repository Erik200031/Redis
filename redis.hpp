#include "redis.h"


void myl::Redis::lpush(const String& name,const String& value) 
{
    m_umsl[name].push_back(value);
}

String myl::Redis::get_list(const String& name, int beg = 0,int end = 0) 
{
    if(beg>end)
    {
        std::cout<<"Invalid index"<<std::endl;
        return " ";
    }
    String str;
    int left_bound=0;
    int right_bound=m_umsl[name].size()-1;
    for(auto it=m_umsl[name].begin(); it!=m_umsl[name].end(); ++it)
    {

        if (beg==0 and end==0)
        {
            str=str+(*it);
            str=str + '\n';
        }
        else
        {
            if(left_bound>=beg )
            {
                if(end<=right_bound)
                {
                    str=str+(*it);
                    str=str + '\n';
                }
                else
                {
                    --right_bound;
                }
            }
            else
            {
                --left_bound;
            }
        }
    }
    return str;
}

void myl::Redis::um_push(const String& name,const String& key,const String&value) 
{
    m_umum.emplace(name,Unordered_map<String,String>(key,value));
}

String myl::Redis::get_um(const String& name, const String& key) 
{
    return m_umum.at(name).at(key);
}

void myl::Redis::clear_um(const String& name)
{
    m_umum[name].clear();
}

void myl::Redis::push_str(const String& name, const String& str) 
{
     m_umss[name]+=str;
}

String myl::Redis::get_str(const String& name)  
{
    return m_umss.at(name);
}

