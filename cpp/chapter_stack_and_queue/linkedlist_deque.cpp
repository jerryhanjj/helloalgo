#include "../utils/common.hpp"

/*
双向队列，头部和尾部都可以执行入队和出队操作

实现方式：
- 双向链表
- 循环数组
*/

class LinkedListDeque
{
private:
    DoublyListNode *head;
    DoublyListNode *rear;
    int queSize;

public:
    LinkedListDeque();
    ~LinkedListDeque();
    int getSize();
    bool isEmpty();
    void pushFirst(int num);
    void pushLast(int num);
    int popFirst();
    int popLast();
    int peekFirst();
    int peekLast();
    vector<int> queToVector();

private:
    void push(int num, bool isFront);
    int pop(bool isFront);
};

LinkedListDeque::LinkedListDeque() : head(nullptr), rear(nullptr)
{
}

LinkedListDeque::~LinkedListDeque()
{
    DoublyListNode *pre = nullptr;
    DoublyListNode *cur = head;

    while (cur != nullptr)
    {
        pre = cur;
        cur = cur->next;
        delete pre;
    }
}

int LinkedListDeque::getSize()
{
    return queSize;
}

bool LinkedListDeque::isEmpty()
{
    return getSize() == 0;
}

void LinkedListDeque::push(int num, bool isFront)
{
    DoublyListNode *node = new DoublyListNode(num);

    // 如果队列为空
    if (isEmpty())
    {
        head = rear = node;
    }
    else if (isFront)
    {
        head->prev = node;
        node->next = head;
        head = node;
    }
    else
    {
        rear->next = node;
        node->prev = rear;
        rear = node;
    }

    queSize++;
}

void LinkedListDeque::pushFirst(int num)
{
    push(num, true);
}

void LinkedListDeque::pushLast(int num)
{
    push(num, false);
}

int LinkedListDeque::popFirst()
{
    return pop(true);
}

int LinkedListDeque::popLast()
{
    return pop(false);
}

int LinkedListDeque::peekFirst()
{
    return head->val;
}

int LinkedListDeque::peekLast()
{
    return rear->val;
}

vector<int> LinkedListDeque::queToVector()
{
    DoublyListNode *node = head;
    vector<int> res(getSize());
    for (int i = 0; i < res.size(); i++)
    {
        res[i] = node->val;
        node = node->next;
    }
    return res;
}

int LinkedListDeque::pop(bool isFront)
{
    if (isEmpty())
    {
        return 0;
    }

    int val;
    DoublyListNode *node = nullptr;

    if (isFront)
    {
        val = head->val;

        node = head;
        head = head->next;
        head->prev = nullptr;
        node->next = nullptr;
        node->prev = nullptr;

        if (getSize() == 1)
        {
            rear->next = nullptr;
            rear->prev = nullptr;
        }
    }
    else
    {
        val = rear->val;

        node = rear;
        rear = rear->prev;
        rear->next = nullptr;
        node->prev = nullptr;
        node->next = nullptr;

        if (getSize() == 1)
        {
            head->next = nullptr;
            head->prev = nullptr;
        }
    }

    delete node;
    queSize--;

    return val;
}

int main()
{
    /* 初始化双向队列 */
    LinkedListDeque *deque = new LinkedListDeque();
    deque->pushLast(3);
    deque->pushLast(2);
    deque->pushLast(5);
    cout << "deque = ";
    printVector(deque->queToVector());

    /* 访问元素 */
    int peekFirst = deque->peekFirst();
    cout << "deque peekFirst = " << peekFirst << endl;
    int peekLast = deque->peekLast();
    cout << "deque peekLast = " << peekLast << endl;

    /* 元素入队 */
    deque->pushLast(4);
    cout << "elem 4 push last, deque =";
    printVector(deque->queToVector());
    deque->pushFirst(1);
    cout << "elem 1 push first, deque = ";
    printVector(deque->queToVector());

    /* 元素出队 */
    int popLast = deque->popLast();
    cout << "pop last = " << popLast << ", deque = ";
    printVector(deque->queToVector());
    int popFirst = deque->popFirst();
    cout << "pop first = " << popFirst << ", deque = ";
    printVector(deque->queToVector());

    /* 获取双向队列的长度 */
    int size = deque->getSize();
    cout << "deque size = " << size << endl;

    /* 判断双向队列是否为空 */
    bool isEmpty = deque->isEmpty();
    cout << "deque is empty = " << boolalpha << isEmpty << endl;

    // 释放内存
    delete deque;

    return 0;
}