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
        node->next = nullptr;
        node->prev = nullptr;

        delete node;

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
        node->prev = nullptr;
        node->next = nullptr;

        delete node;

        if (getSize() == 1)
        {
            head->next = nullptr;
            head->prev = nullptr;
        }
    }

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

    return 0;
}