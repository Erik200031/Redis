#include"redis.h"
// #include "./parser/parser.h"
// #include"./set/set.h"
//#include "./utility/utility.h"
//#include"./Priority_queue/P_Queue.h"


int main()
{
  myl::String str1,str2,str3,str4;
     std::cin>>str1;
    std::cin>>str2;
    std::cin>>str3;
    // std::cin>>str4;
    myl::Redis ob;
    myl::vector<myl::String>vec;
     vec.push_back(str1);
     vec.push_back(str2);
   //vec.push_back(str3);
  //  vec.push_back(str4);

   /*std::cout<<ob.lpush(vec)<<std::endl;
    std::cout<<ob.get_list(vec)<<std::endl;
    std::cout<<ob.clear_list(vec)<<std::endl;*/
  //   std::cout<<ob.um_push(vec)<<std::endl;
  //   std::cout<<ob.get_um(vec)<<std::endl;
  //   std::cout<<ob.clear_um(vec)<<std::endl;
  //   std::cout<<ob.set_queue(vec)<<std::endl;
  //  std::cout<<ob.get_queue(vec)<<std::endl;
  //   std::cout<<ob.get_queue_top(vec)<<std::endl;
  //  std::cout<<ob.clear_queue(vec)<<std::endl;
  //  std::cout<<ob.str_push(vec)<<std::endl;
  //  std::cout<<ob.get_str(vec)<<std::endl;
  // std::cout<<ob.clear_str(vec)<<std::endl;
  // std::cout<<ob.set_push(vec)<<std::endl;
  // std::cout<<ob.get_set(vec)<<std::endl;
  // std::cout<<ob.clear_set(vec)<<std::endl;

  std::cout<<ob.Redis_work(vec)<<std::endl;
    return 0;

}
