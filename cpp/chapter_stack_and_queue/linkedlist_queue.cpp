#include "../utils/common.hpp"

class LinkedListQueue
{
private:
    ListNode *head;
    ListNode *rear;
    int queSize;

public:
    LinkedListQueue()
    {
        // 初始化
        head = nullptr;
        rear = nullptr;
        queSize = 0;
    }

    ~LinkedListQueue()
    {
        // 析构函数 释放内存
        freeMemoryLinkedList(head);
    }

    // 入队
    void push(int num)
    {
        // 在队尾添加元素
        ListNode *newNode = new ListNode(num);
        if (nullptr == head)
        {
            // 空队列添加第一个元素头节点的处理
            head = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        queSize++;
    }

    // 出队
    void pop()
    {
        
    }
};