#include "set.h"

int main()
{
    myl::set<int> s {1, 2, 3};
    myl::set<int> s2(s);
    s2.insert(13);
    s2.insert(5);
    s2.insert(-13);
    s2.erase(13);
    s2.print();
    s2 = std::move(s);
    s2.print();

}