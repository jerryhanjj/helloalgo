/*
基于动态数组实现栈
*/
#include "../utils/common.hpp"

class ArrayStack
{
private:
    vector<int> myStack;

public:
    ArrayStack();
    ~ArrayStack();
    int getSize();
    bool isEmpty();
    void push(int num);
    int pop();
    int top();
    vector<int> stackToVector();
};

ArrayStack::ArrayStack()
{
}

ArrayStack::~ArrayStack()
{
}

int ArrayStack::getSize()
{
    return myStack.size();
}

bool ArrayStack::isEmpty()
{
    return 0 == myStack.size();
}

void ArrayStack::push(int num)
{
    myStack.push_back(num);
}

int ArrayStack::pop()
{
    int topValue = top();
    myStack.pop_back();

    return topValue;
}

int ArrayStack::top()
{
    if (!isEmpty())
    {
        return myStack.back();
    }

    return 0;
}

vector<int> ArrayStack::stackToVector()
{
    return myStack;
}

int main()
{
    ArrayStack *myStack = new ArrayStack();

    myStack->push(1);
    myStack->push(3);
    myStack->push(2);
    myStack->push(5);
    myStack->push(4);

    cout << "stack = ";
    printVector(myStack->stackToVector());

    int top = myStack->top();
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