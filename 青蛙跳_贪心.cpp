#include <iostream>
using namespace std;
int main()
{
    int n,a[10000], i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] >= n - i)
        {
            count++;
            n = i;
            i = -1;
        }
    }
    if (n != 0)
    {
        cout << -1;
    }
    else
        cout << count;
    return 0;
}