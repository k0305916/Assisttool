#include <iostream>

int jumpFloor(int number)
{
    if(number == 1 || number == 0)
        return 1;

    return jumpFloor(number-1)+jumpFloor(number-2);
}

int main()
{
    std::cout<<jumpFloor(4)<<std::endl;
    return 0;
}