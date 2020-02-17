# LeetCode_LCCI
LeetCode中《程序员面试金典》编程题
# 仓库说明
## 1.时间轴
|<center>时间</center>|<center>记录内容</center>|<center>备注</center>|
|:---|:---|:---|
|2020年2月17日|开始着手刷题|起步|

## 2.内容描述
&emsp;&emsp;本仓库链接：https://github.com/guyongpu/LeetCode_LCCI.git
&emsp;&emsp;本仓库为LeetCode刷题记录，网址为：https://leetcode-cn.com/problemset/lcci/ ，[点击跳转到LeetCode中文题库](https://leetcode-cn.com/problemset/lcci/)
每个题的代码放在src中，在main.cpp设置prob_num的值，prob_num为题目编号，然后运行测试函数即可，例如需要运行题1时，在main.cpp中设置prob_num=1即可:
~~~ c++
#include <iostream>

#include "src/P0000_Solutions.h"

using namespace std;

int main() {
    int prob_num = 2;
    P0000_Solutions obj;
    obj.test(prob_num);
    cout << "Probelem " << prob_num << " run finish!" << endl;
    return 0;
}
~~~

&emsp;&emsp;然后点击运行即可，题1结果如下：
~~~c++
0
1
Probelem 1 run finish!

Process finished with exit code 0
~~~

## 3.文件说明
|<center>文件名</center>|<center>内容描述</center>|
|:---|:---|
|P0000_CommonHead.h|用于声明一些公用的结构体或者函数，如树节点、链表节点等，在需要的时候引用.|
|P0000_Solutions.h|用于测试的头文件，则其中引入各个文件的头文件，用于创建各个问题的类.|
|P0000_Solutions.cpp|用于测试的源程序，在switch函数中创建并调用各个问题类的test()函数进行运行测试.|
|Pxxxx_*******.h|表示编号为xxxx问题的类的头文件.|
|Pxxxx_*******.cpp|表示编号为xxxx问题的类的头文件相对应的源程序.|

## 4.刷题日志
|<center>题号</center>|<center>题目名</center>|<center>完成日期</center>|<center>描述</center>|<center>备注</center>|
|:---:|:---:|:---:|:---|:---|
|P0001_01|判定字符是否唯一|2020.2.17|描述：实现一个算法，确定一个字符串 s 的所有字符是否全都不同.<br>思路：可以使用排序，集合方法做，此处采用排序方法，未使用额外内存.|基础题|
|P0001_02|判定是否互为字符重排|2020.2.17|描述：给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串.<br>思路：法1，直接排序后比较；法2，可以通过HashMap的方法比较s1和s2中字符出现次数是否相等.|掌握法1和法2|

