

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr)
        return pHead2;
    else if (pHead2 == nullptr)
        return pHead1;

    ListNode result = pHead1->val < pHead2->val ? *pHead1 : *pHead2;
    if (pHead1->val <= pHead2->val)
        pHead1 = pHead1->next;
    else
        pHead2 = pHead2->next;
    ListNode *presult = &result;
    while (pHead1 != nullptr && pHead2 != nullptr)
    {
        if (pHead1->val <= pHead2->val)
        {
            presult->next = pHead1;
            presult = presult->next;

            pHead1 = pHead1->next;
        }
        else
        {
            presult->next = pHead2;
            presult = presult->next;

            pHead2 = pHead2->next;
        }
    }
    if(pHead1 == nullptr)
        presult->next = pHead2;
    else
        presult->next = pHead1;
    pHead1 = &result;
    return pHead1;
}

int main()
{
    ListNode item1(1);
    ListNode item2(7);
    ListNode item3(9);
    ListNode item4(3);
    ListNode item5(4);
    ListNode item6(6);

    item1.next = &item2;
    item2.next = &item3;
    //item3.next = &item4;
    item4.next = &item5;
    item5.next = &item6;

    auto result = Merge(&item1,&item4);
    return 0;
}