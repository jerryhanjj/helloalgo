#ifndef _PRINT_UTILS_H_
#define _PRINT_UTILS_H_

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
string strJoin(const string &delim, const T &vec)
{
    ostringstream oss;

    // 逻辑：如果不是第一个元素，则在元素前面添加一个分割符
    // for (const auto &i : vec)
    // {
    //     if (&i != &vec[0])
    //     {
    //         oss << delim;
    //     }
    //     oss << i;
    // }

    // 逻辑：如果不是最后一个元素，则在元素后面添加一个分割符
    for (const auto &i : vec)
    {
        oss << i;
        if (&i != &vec.back())
        {
            oss << delim;
        }
    }

    return oss.str();
}

template <typename T>
string getVectorString(vector<T> &vec)
{
    return "[" + strJoin(", ", vec) + "]";
}

template <typename T>
void printVector(vector<T> vec)
{
    cout << getVectorString(vec) << endl;
}

#endif