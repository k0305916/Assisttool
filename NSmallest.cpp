#include <iostream>

int GetNSmallest(int arr[],int length, int m)
{
    auto cur = arr[0];
    auto largestart = 0;
    auto largeend = 0;
    for(auto i=1;i<length;i++)
    {
        if(cur > arr[i])
        {
            auto tmp = arr[i];
            arr[i] = cur;
            cur = tmp;
        }
        cur = arr[i];
    }
    
    return 0;
}

int main()
{
    int testvalue[] = {3,5,2,10,1,15};
    auto result = GetNSmallest(testvalue,6,3);
    std::cout<< result <<std::endl;
    return 0;
}