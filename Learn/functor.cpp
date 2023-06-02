#include <iostream>

struct max {
    int operator()(int a, int b){
        return (a > b) ? a : b;
    }
};

int main()
{
    max maxi;
    
    std::cout << maxi(5, 7) << std::endl;
}