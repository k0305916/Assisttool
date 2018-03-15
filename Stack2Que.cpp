#include <stack>
#include <iostream>

using namespace std;
class Solution
{
  public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        if (stack1.size() <= 0)
            return -1;
        
        while(stack1.size() != 1)
        {
            stack2.push(stack1.top());
            stack1.pop();
        }

        auto result = stack1.top();
        stack1.pop();

        while(stack2.size() != 0)
        {
            stack1.push(stack2.top());
            stack2.pop();
        }

        return result;
    }

  private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    return 0;
}