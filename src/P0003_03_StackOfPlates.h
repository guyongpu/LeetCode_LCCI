//
// Created by yongpu on 2020/2/22.
//

#ifndef LEETCODE_LCCI_P0003_03_STACKOFPLATES_H
#define LEETCODE_LCCI_P0003_03_STACKOFPLATES_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class P0003_03_StackOfPlates {
public:
    vector<stack<int> *> SS;
    stack<int> *stack_curr;
    int capture;

    P0003_03_StackOfPlates(int cap);

    void push(int val);

    int pop();

    int popAt(int index);

    int test();
};


#endif //LEETCODE_LCCI_P0003_03_STACKOFPLATES_H
