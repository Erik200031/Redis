#include"redis.h"
#include "./parser/parser.h"

int main()
{

    String str1;
    std::cin>>str1;
    Parser p(str1);
    p.parse_code();
    vector<String> vec;
    vec = p.get_tokens();
    for (size_t i = 0; i < vec.getSize(); i++)
    {
        std::cout<<vec[i]<<" ";
    }
    

    return 0;

}