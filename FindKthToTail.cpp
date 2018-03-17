#include <iostream>
#include <stack>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
{
    if (k <= 0 || pListHead == nullptr)
        return nullptr;
    std::stack<ListNode *> temp;
    auto count =0;
    while (pListHead->next != nullptr)
    {
        temp.push(pListHead);
        pListHead = pListHead->next;
        count++;
    }
    temp.push(pListHead);

    if(k>count)
        return nullptr;

    while (k-- - 1)
    {
        temp.pop();
    }

    return temp.top();
}

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
    auto result = FindKthToTail(&item1,6);
    return 0;
}