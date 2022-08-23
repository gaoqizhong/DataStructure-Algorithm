# CppSTL priority_queue 优先级队列

【参考资料】[C++ STL priority_queue容器适配器详解](http://c.biancheng.net/view/6987.html)

目录

[TOC]

### 1、优先级队列

First in, Largest out

- 遵循 “First in，Largest out”，即：先进队列的元素并不一定先出队列，而是优先级最高的元素最先出队列

> priority_queue 容器适配器在创建时，都制定了一种排序规则。根据此规则，该容器适配器中存储的元素就有了优先级高低之分

实现原理

- priority_queue 容器适配器为了保证每次从队头移除的都是当前优先级最高的元素，每当有新元素进入，它都会根据既定的排序规则找到优先级最高的元素，并将其移动到队列的队头；同样，当 priority_queue 从队头移除出一个元素之后，它也会再找到当前优先级最高的元素，并将其移动到队头

- 其底层采用堆实现

 时间复杂度

- 【建堆】O(n)
- 【in/out】O(logn)

### 2、声明方式

- priority_queue 可以有三个参数
- priority_queue<数据类型， 容器类型， 排序规则>

头文件

```cpp
#include <queue>
```

创建一个空的 priority_queue

```cpp
// 采用默认的 vector 容器，排序方式也采用默认的 less<T>
priority_queue<int> heap;
```

创建一个有初始值的 priority_queue

```cpp
// 指定容器类型，排序方式采用默认的 less<T>
int value1[] = {4,1,3,2};
priority_queue<int> heap1(value1,value1+4);

vector<int> value2 = {4,1,3,2};
priority_queue<int> heap2(value2.begin(), value2.end());
```

自定义排序规则

```cpp
// 使用 greater<int>
vector<int> value = {4,1,3,2};
priority_queue<int, vector<int>, greater<int>> 
heap(value.begin(), value2.end());

// 使用自定义 rule
struct rule {
	bool operator() (const int& a, const int& b) {
        return a > b;
    }
};
priority_queue<int, vector<int>, rule> 
heap1(value.begin(), value2.end());
```

### 3、成员函数

| 成员函数                       | 功能                                                         |
| ------------------------------ | ------------------------------------------------------------ |
| empty()                        | 如果 priority_queue 为空的话，返回 true；反之，返回 false。  |
| size()                         | 返回 priority_queue 中存储元素的个数。                       |
| top()                          | 返回 priority_queue 中第一个元素的引用形式。                 |
| push(const T& obj)             | 根据既定的排序规则，将元素 obj 的副本存储到 priority_queue 中适当的位置。 |
| push(T&& obj)                  | 根据既定的排序规则，将元素 obj 移动存储到 priority_queue 中适当的位置。 |
| emplace(Args&&... args)        | Args&&... args 表示构造一个存储类型的元素所需要的数据（对于类对象来说，可能需要多个数据构造出一个对象）。此函数的功能是根据既定的排序规则，在容器适配器适当的位置直接生成该新元素。 |
| pop()                          | 移除 priority_queue 容器适配器中第一个元素。                 |
| swap(priority_queue<T>& other) | 将两个 priority_queue 容器适配器中的元素进行互换，需要注意的是，进行互换的 2 个 priority_queue 容器适配器中存储的元素类型以及底层采用的基础容器类型，都必须相同。 |

### 4、示例

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    vector<int> values = {4, 1, 2, 3};

    // 默认方法
    priority_queue<int> heap1(values.begin(), values.end());
    // 指定排序规则 greater<int>
    priority_queue<int, vector<int>, greater<int>>
    heap2(values.begin(), values.end());
    // 自定义排序规则 rule
    struct rule {
        bool operator() (const int& a, const int& b) {
            return a > b;
        }
    };
    priority_queue<int, vector<int>, rule> 
    heap3(values.begin(), values.end());

    cout << heap1.top() << endl
         << heap2.top() << endl
         << heap3.top() << endl;

    return 0;
}

/*
-> 4
-> 1
-> 1
*/
```

