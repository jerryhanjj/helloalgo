#include "../utils/common.hpp"
#include <vector>

using namespace std;

class LinkedListStack
{
private:
    ListNode *stackTop; // 头节点作为栈顶，采用头插法
    int stackSize;

public:
    LinkedListStack();
    ~LinkedListStack();
    int getSize();
    bool isEmpty();
    void push(int num);
    int pop();
    bool top(int *topVal);
    vector<int> stackToVector();
};

LinkedListStack::LinkedListStack()
{
    stackTop = nullptr;
    stackSize = 0;
}

LinkedListStack::~LinkedListStack()
{
    freeMemoryLinkedList(stackTop);
}

int LinkedListStack::getSize()
{
    return stackSize;
}

bool LinkedListStack::isEmpty()
{
    return getSize() == 0;
}

void LinkedListStack::push(int num)
{
    ListNode *newNode = new ListNode(num);
    newNode->next = stackTop;
    stackTop = newNode;
    stackSize++;
}

int LinkedListStack::pop()
{
    ListNode *delNode = stackTop;
    int delTopVal = 0;
    top(&delTopVal);

    stackTop = stackTop->next;
    delete delNode;
    stackSize--;

    return delTopVal;
}

bool LinkedListStack::top(int *topVal)
{
    if (isEmpty())
    {
        return false;
    }

    *topVal = stackTop->val;

    return true;
}

vector<int> LinkedListStack::stackToVector()
{
    ListNode *stackNode = stackTop;
    int stackSize = getSize();
    vector<int> res(stackSize);

    for (int i = stackSize - 1; i >= 0; i--)
    {
        // 为何此处不实用push，一试便知
        // res.push_back(stackNode->val);
        res[i] = stackNode->val;
        stackNode = stackNode->next;
    }

    return res;
}

// 已废弃，被同名模版函数替换
// void printVector(vector<int> vec)
// {
//     cout << "[";
//     for (const auto &num : vec)
//     {
//         cout << num << ",";
//     }
//     cout << "]" << endl;
// }

int main()
{
    // 初始化栈
    LinkedListStack *myStack = new LinkedListStack();

    myStack->push(1);
    myStack->push(3);
    myStack->push(2);
    myStack->push(5);
    myStack->push(4);

    // vector<int> stack2vec = myStack->stackToVector();
    cout << "stack = ";
    printVector(myStack->stackToVector());

    int top;
    myStack->top(&top);
    cout << "stack top = " << top << endl;

    top = myStack->pop();
    cout << "stack pop = " << top << ", stack after  = ";
    printVector(myStack->stackToVector());

    int size = myStack->getSize();
    cout << "stack size = " << size << endl;

    bool empty = myStack->isEmpty();
    cout << "stack is empty = " << empty << endl;

    delete myStack;

    return 0;
}