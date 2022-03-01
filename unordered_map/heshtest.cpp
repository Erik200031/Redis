#include<iostream>
//#include<string>
#include "../string/string.h"



struct hesh
{
	hesh() = default;
	uint32_t operator()(const String& ob, const uint32_t& tabel_size) const
	{
		uint32_t h = 0, rand_number_1 = 123457, rand_number_2 = 752432;
		for (int32_t i=0; i != ob.size(); ++i)
		{
			h = (rand_number_1 * h + static_cast<int>(ob[i])) % tabel_size;
			rand_number_1 = ((rand_number_1 * rand_number_2) % (tabel_size - 1));
		}
		return h < 0 ? h + tabel_size : h;
	}
};


int main()
{
    String st = "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
    std::cin>>st;
    //getline(std::cin,st);
    hesh obj;
    uint32_t ind=obj(st,500);
    std::cout<<ind;
    std::cout<<st;
}