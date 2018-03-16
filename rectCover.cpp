#include <iostream>

int rectCover(int number)
{
    if (number == 0)
        return 0;
    else if (number == 1)
        return 1;
    else if (number == 2)
        return 2;
    return rectCover(number - 1) + rectCover(number - 2);
}

int main()
{
    std::cout << rectCover(3) << std::endl;
    return 0;
}