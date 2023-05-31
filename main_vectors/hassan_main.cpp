#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <stdlib.h>
#include "../containers/vector.hpp"
// #include 

class L
{
    public:
    int *p;
    L()
    {
        p = (int *) malloc(1000);
    }
    L(const L &old)
    {
        (void) old;
        p = (int *)malloc(1000);
    }
    L &operator=(const L &old)
    {
        free(p);
        (void) old;
        p = (int *)malloc(1000);
        return *this;
    }
    ~L()
    {
        free(p);
    }
};



int main()
{
    ft::vector<L> a;

    a.insert(a.begin(), L());
    a.insert(a.begin(), 1000 , L());
}