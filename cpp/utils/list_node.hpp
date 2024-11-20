#ifndef _LIST_NODE_H_
#define _LIST_NODE_H_

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void freeMemoryLinkedList(ListNode *head)
{
    ListNode *cur = nullptr;
    ListNode *temp = nullptr;

    cur = head;

    while (nullptr != cur)
    {
        temp = cur;
        cur = cur->next;
        delete temp;
    }
}

#endif