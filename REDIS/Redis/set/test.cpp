#include "set.h"
#include <iostream>

int main()
{
    myl::String str;
    
    myl::set<myl::String> s{"69", "73", "76","68","75","110"};
    s.copy_str(str);

     std::cout<<str<<" ";

   
   return 0;

}
