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

struct DoublyListNode
{
    int val;
    DoublyListNode *prev; // 前驱结点指针
    DoublyListNode *next; // 后继结点指针
    DoublyListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

#endif