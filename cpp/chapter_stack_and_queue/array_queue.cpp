#include "../utils/common.hpp"

/*
基于数组实现的队列：
1. 出队（删除首元素）的时间复杂度为 O(n)
2. 可以通过head的队列size计算出rear，实现O(1)效率
3. 循环队列，长度固定
4. 可以使用动态数组，实现扩容
*/

class ArrayQueue
{
private:
    int *nums;       // 存储元素的数组
    int head;        // 队首索引
    int rear;        // 队尾
    int queSize;     // 长度
    int queCapacity; // 容量

public:
    ArrayQueue(int);
    ~ArrayQueue();
    int getCapacity();
    int getSize();
    bool isEmpty();
    void push(int num);
    int pop();
    int peek();
    vector<int> queueToVector();
};

ArrayQueue::ArrayQueue(int capacity)
{
    nums = new int[capacity];
    queCapacity = capacity;
    head = 0;
    rear = 0;
    queSize = 0;
}

ArrayQueue::~ArrayQueue()
{
    delete[] nums;
}

int ArrayQueue::getCapacity()
{
    return queCapacity;
}

int ArrayQueue::getSize()
{
    return queSize;
}

bool ArrayQueue::isEmpty()
{
    return getSize() == 0;
}

void ArrayQueue::push(int num)
{
    if (queSize == queCapacity)
    {
        cout << "queue already full !" << endl;
        return;
    }

    nums[rear] = num;
    rear = (rear + 1) % queCapacity;
    queSize++;
}

int ArrayQueue::pop()
{
    if (!isEmpty())
    {
        int headVal = peek();
        head = (head + 1) % queCapacity;
        queSize--;
        return headVal;
    }

    return 0;
}

int ArrayQueue::peek()
{
    if (!isEmpty())
    {
        return nums[head];
    }

    cout << "queue is empty !" << endl;
    return 0;
}

vector<int> ArrayQueue::queueToVector()
{
    vector<int> vecQue(queSize);

    for (int i = 0, j = head; i < queSize; i++, j++)
    {
        vecQue[i] = nums[j % queCapacity];
    }

    return vecQue;
}

int main()
{
    /* 初始化队列 */
    int capacity = 10;
    ArrayQueue *queue = new ArrayQueue(capacity);

    /* 元素入队 */
    queue->push(1);
    queue->push(3);
    queue->push(2);
    queue->push(5);
    queue->push(4);
    cout << "queue = ";
    printVector(queue->queueToVector());

    /* 访问队首元素 */
    int peek = queue->peek();
    cout << "queue peek = " << peek << endl;

    /* 元素出队 */
    peek = queue->pop();
    cout << "queue pop = " << peek << ", queue = ";
    printVector(queue->queueToVector());

    /* 获取队列的长度 */
    int size = queue->getSize();
    cout << "queue size = " << size << endl;

    /* 判断队列是否为空 */
    bool empty = queue->isEmpty();
    cout << "queue is empty = " << empty << endl;

    /* 测试环形数组 */
    for (int i = 0; i < 10; i++)
    {
        queue->push(i);
        queue->pop();
        cout << "roud " << i << " push and pop, queue = ";
        printVector(queue->queueToVector());
    }

    // 释放内存
    delete queue;

    return 0;
}