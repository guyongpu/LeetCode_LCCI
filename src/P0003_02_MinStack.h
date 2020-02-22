//
// Created by yongpu on 2020/2/22.
//

#ifndef LEETCODE_LCCI_P0003_02_MINSTACK_H
#define LEETCODE_LCCI_P0003_02_MINSTACK_H

#include <iostream>
#include <vector>

using namespace std;

class P0003_02_MinStack {
public:

    vector<int> arr;
    vector<int> min;

    P0003_02_MinStack();

    void push(int x);

    void pop();

    int top();

    int getMin();

    int test();
};


#endif //LEETCODE_LCCI_P0003_02_MINSTACK_H
