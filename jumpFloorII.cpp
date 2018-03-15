#include <iostream>

int jumpFloorII(int number)
{
    if(number == 0 || number == 1)
        return 1;
    
    auto sum = 0;
    while(--number>=0)
    {
        sum+=jumpFloorII(number);
    }
    return sum;
}

int main()
{
    std::cout << jumpFloorII(4) << std::endl;
    return 0;
}