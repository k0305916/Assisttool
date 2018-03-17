#include <iostream>
#include <vector>

using namespace std;
void reOrderArray(vector<int> &array)
{
    vector<int> q, o;
    for (auto value : array)
    {
        if (value % 2 == 0)
            o.push_back(value);
        else
            q.push_back(value);
    }

    std::copy(array, q);
    std::copy(array + q.size(), o);
}

int main()
{
    vector<int> tp;
    tp.push_back(1);
    cout<< "Hello World" << endl;
}