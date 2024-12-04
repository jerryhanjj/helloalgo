#include "../utils/common.hpp"

/*
没有冲突的简单的hash实现
*/

struct Pair
{
public:
    int key;
    string val;
    Pair(int key, string val)
    {
        this->key = key;
        this->val = val;
    }
};

class ArrayHashMap
{
private:
    vector<Pair *> buckets;

public:
    ArrayHashMap();
    ~ArrayHashMap();
    int hashFunc(int key);         // 哈希函数
    string get(int key);           // 查询函数
    void put(int key, string val); // 添加元素
    void remove(int key);          // 删除元素
    void print();
};

ArrayHashMap::ArrayHashMap()
{
    buckets = vector<Pair *>(100);
}

ArrayHashMap::~ArrayHashMap()
{
    // 考虑使用智能指针，避免手动释放
    for (auto &bucket : buckets)
    {
        delete bucket;
    }
    buckets.clear();
}

int ArrayHashMap::hashFunc(int key)
{
    int index = key % 100;
    return index;
}

string ArrayHashMap::get(int key)
{
    int index = hashFunc(key);
    string val = "";

    Pair *pair = buckets[index];
    if (pair != nullptr)
    {
        val = pair->val;
    }

    return val;
}

void ArrayHashMap::put(int key, string val)
{
    Pair *pair = new Pair(key, val);
    int index = hashFunc(key);
    buckets[index] = pair;
}

void ArrayHashMap::remove(int key)
{
    int index = hashFunc(key);
    delete buckets[index];
    buckets[index] = nullptr;
}

void ArrayHashMap::print()
{
    for (auto &pair : buckets)
    {
        if (pair != nullptr)
        {
            cout << pair->key << " -> " << pair->val << endl;
        }
    }
}

int main()
{
    /* 初始化哈希表 */
    ArrayHashMap map = ArrayHashMap();

    /* 添加操作 */
    // 在哈希表中添加键值对 (key, value)
    map.put(12836, "小哈");
    map.put(15937, "小啰");
    map.put(16750, "小算");
    map.put(13276, "小法");
    map.put(10583, "小鸭");
    cout << "\n添加完成后，哈希表为\nKey -> Value" << endl;
    map.print();

    /* 查询操作 */
    // 向哈希表中输入键 key ，得到值 value
    string name = map.get(15937);
    cout << "\n输入学号 15937 ，查询到姓名 " << name << endl;

    /* 删除操作 */
    // 在哈希表中删除键值对 (key, value)
    map.remove(10583);
    cout << "\n删除 10583 后，哈希表为\nKey -> Value" << endl;
    map.print();

    return 0;
}
