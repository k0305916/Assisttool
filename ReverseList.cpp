#include <stack>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

ListNode *ReverseList(ListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;
    ListNode *pHeadtemp = pHead;
    std::stack<ListNode *> temp;
    auto count = 0;
    while (pHead->next != nullptr)
    {
        temp.push(pHead);
        pHead = pHead->next;
        count++;
    }
    temp.push(pHead);
    count++;

    pHeadtemp = temp.top();
    pHead = pHeadtemp;
    for (auto i = 0; i < count; i++)
    {
        temp.pop();
        if(i == count-1)
        {
            pHeadtemp->next = nullptr;
            continue;
        }
        pHeadtemp->next = temp.top();
        pHeadtemp = pHeadtemp->next;
    }
    return pHead;
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
    auto result = ReverseList(&item1);
    return 0;
}