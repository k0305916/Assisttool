#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

vector<int> Print(ListNode *head){
    vector<int> result;
    if(head == nullptr)
        return std::move(result);
    stack<int> temp;
    while(head->next != nullptr)
    {
        temp.push(head->val);
        head = head->next;
    }
    temp.push(head->val);

    while(!temp.empty())
    {
        result.push_back(temp.top());
        temp.pop();
    }
    return std::move(result);
};

int main()
{
    ListNode item1(1);
    ListNode item2(2);
    ListNode item3(3);
    ListNode item4(4);
    ListNode item5(5);
    ListNode item6(6);

    item1.next = &item2;
    item2.next = &item3;
    item3.next = &item4;
    item4.next = &item5;
    item5.next = &item6;

    auto result = Print(&item1);
    for (auto value : result)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}