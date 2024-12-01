#include "../utils/common.hpp"

class ArrayDeque
{
private:
    vector<int> nums;
    int head;
    int queSize;

public:
    ArrayDeque(int capacity);
    ~ArrayDeque();
    int capacity();
    int size();
    bool isEmpty();
    int index(int idx);
    void pushFirst(int num);
    void pushLast(int num);
    int popFirst();
    int popLast();
    int peekFirst();
    int peekLast();
    vector<int> queToVector();
};

ArrayDeque::ArrayDeque(int capacity)
{
    // vector重新初始化为capacity个元素默认值
    nums.resize(capacity);
    head = 0;
    queSize = 0;
}

ArrayDeque::~ArrayDeque()
{
}

int ArrayDeque::capacity()
{
    // capacity()方法获取到的vector容量是扩容前最大容量
    // size()方法获取vector当前元素个数
    // 此处的容量指的是初始化默认值后vector的长度
    return nums.size();
}

int ArrayDeque::size()
{
    return queSize;
}

bool ArrayDeque::isEmpty()
{
    return size() == 0;
}

int ArrayDeque::index(int idx)
{
    return (idx + capacity()) % capacity();
}

void ArrayDeque::pushFirst(int num)
{
    if (queSize == capacity())
    {
        cout << "deque is full." << endl;
        return;
    }
    head = index(head - 1);
    nums[head] = num;
    queSize++;
}

void ArrayDeque::pushLast(int num)
{
    if (queSize == capacity())
    {
        cout << "deque is full." << endl;
        return;
    }
    int rear = index(head + queSize);
    nums[rear] = num;
    queSize++;
}

int ArrayDeque::popFirst()
{
    int firstVal = peekFirst();
    head = index(head + 1);
    queSize--;

    return firstVal;
}

int ArrayDeque::popLast()
{
    return 0;
}

int ArrayDeque::peekFirst()
{
    return nums[head];
}

int ArrayDeque::peekLast()
{
    return nums[head + queSize - 1];
}

vector<int> ArrayDeque::queToVector()
{
    // 仅转换有效长度范围内的列表元素
    vector<int> res(queSize);
    for (int i = 0, j = head; i < queSize; i++, j++)
    {
        res[i] = nums[index(j)];
    }
    return res;
}

int main()
{
    /* 初始化双向队列 */
    ArrayDeque *deque = new ArrayDeque(10);
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
    int size = deque->size();
    cout << "deque size = " << size << endl;

    /* 判断双向队列是否为空 */
    bool isEmpty = deque->isEmpty();
    cout << "deque is empty = " << boolalpha << isEmpty << endl;

    // 释放内存
    delete deque;

    return 0;
}