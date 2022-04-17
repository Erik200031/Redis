#ifndef UTILITY_H_
#define UTILITY_H_
#include <math.h>
#include <string>

#include"../vector/vector.h"

struct Utility
{
    static int stoi(const std::string& str) 
    {
 	  myl::vector<int> vec;
 	   for (int i = 0; i < str.size(); ++i) 
        {
 		   vec.push_back(str[i] - '0');
 	   }
 	   int res = 0;
 	   for (int i = vec.size() - 1; i >= 0; --i) 
       {
 		   res += vec[i] * pow(10, vec.size() - i - 1);
	   }
	   return res;
   }
    static unsigned int my_strlen(const char *s);
};

#endif //UTILITY_H_
