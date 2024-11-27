#include "../utils/common.hpp"

class LinkedListQueue
{
private:
    ListNode *head;
    ListNode *rear;
    int queSize;

public:
    LinkedListQueue();
    ~LinkedListQueue();
    void push(int num);
    int pop();
    int getSize();
    int peek();
    bool isEmpty();
    vector<int> queueToVector();
};

LinkedListQueue::LinkedListQueue()
{
    // 初始化
    head = nullptr;
    rear = nullptr;
    queSize = 0;
}

LinkedListQueue::~LinkedListQueue()
{
    // 析构函数 释放内存
    freeMemoryLinkedList(head);
}

void LinkedListQueue::push(int num)
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

int LinkedListQueue::pop()
{
    ListNode *tempNode = head;
    int headVal = peek();

    head = head->next;
    delete tempNode;
    queSize--;

    return headVal;
}

int LinkedListQueue::getSize()
{
    return queSize;
}

int LinkedListQueue::peek()
{
    // 暂不考虑异常情况
    return head->val;
}

bool LinkedListQueue::isEmpty()
{
    bool status = false;

    if (getSize() == 0)
    {
        status = true;
    }

    return status;
}

vector<int> LinkedListQueue::queueToVector()
{
    ListNode *qNode = head;
    int qSize = getSize();
    vector<int> qVec(qSize);

    for (int i = 0; i < qVec.size(); i++)
    {
        /*
        在已经对qVce初始化的情况下，如果使用push_back()那么qVec的大小会变化，
        即使在for循环中循环条件改为i<qSize，qVec中仍然会存在初始化的元素，一试便知。
         */
        // qVec.push_back(qNode->val);
        qVec[i] = qNode->val;
        qNode = qNode->next;
    }

    return qVec;
}

int main()
{
    LinkedListQueue *myQueue = new LinkedListQueue();

    myQueue->push(1);
    myQueue->push(3);
    myQueue->push(2);
    myQueue->push(5);
    myQueue->push(4);
    printVector(myQueue->queueToVector());

    /* 访问队首元素 */
    int peek = myQueue->peek();
    cout << "queue head peek = " << peek << endl;

    /* 元素出队 */
    peek = myQueue->pop();
    cout << "queue pop = " << peek << "after queue = ";
    printVector(myQueue->queueToVector());

    /* 获取队列的长度 */
    int size = myQueue->getSize();
    cout << "queue size = " << size << endl;

    /* 判断队列是否为空 */
    bool empty = myQueue->isEmpty();
    cout << "queue is empty = " << empty << endl;

    // 释放内存
    delete myQueue;

    return 0;
}
