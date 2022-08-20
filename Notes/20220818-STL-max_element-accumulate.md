# CppSTL —— max_element,  accumulate

【参考资料】[C++ STL 算法——最大值max_element，最小值min_element，求和accumulate](<https://blog.csdn.net/qq_43827595/article/details/106019641?ops_request_misc=&request_id=&biz_id=102&utm_term=C++%20STL%20%E6%9C%80%E5%A4%A7%E5%80%BC%E5%87%BD%E6%95%B0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-106019641.142^v41^control,185^v2^tag_show&spm=1018.2226.3001.4187>)

目录

[TOC]

### 1、max_element

```cpp
// Vector数组
int maxValue = *max_element(v.begin(), v.end());
int maxPosition = max_element(v.begin(),v.end()) - v.begin();
// 普通数组
int maxValue = *max_element(a, a + n); 
int maxPosition = max_element(a, a+6) - a;
```

【头文件】```algorithm```

【返回值】迭代器（或指针），通过取 * 得到元素的引用

【时间复杂度】O(n)

【空间复杂度】O(1)

### 2、accumulate

```cpp
// Vector数组
int sumValue = accumulate(v.begin(), v.end(), 0);
// 普通数组
int sumValue = accumulate(a, a + 5, 0);
```

【头文件】```numeric```

【返回值】声明的值

【参数】第三个参数是初始值，必须存在

【时间复杂度】O(n)

【空间复杂度】O(1)
