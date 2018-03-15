#include <iostream>
#include <vector>

using namespace std;
int Fibonacci(int n, vector<int> &que)
{
    if (n == 0)
    {
        que.push_back(0);
        return 0;
    }
    else if (n == 1)
    {
        que.push_back(1);
        que.push_back(1);
        return 1;
    }
    
    auto result = Fibonacci(n - 1, que) + que[n - 2];
    que.push_back(result);
    return result;
}

int Fibonacci(int n)
{
    vector<int> que;
    Fibonacci(n, que);
    return que[n-1];
}

int main()
{
    std::cout << Fibonacci(6);
    return 0;
}