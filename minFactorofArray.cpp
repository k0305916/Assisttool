#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray)
{
    auto iter = std::min_element(rotateArray.begin(), rotateArray.end(), [](int item1, int item2) {
        if (item1 < item2)
            return true;
        return false;
    });
    return *iter;
}

void main()
{
    vector<int> value{3, 4, 5, 1, 2};
    auto result = minNumberInRotateArray(value);
    std::cout << result;
}