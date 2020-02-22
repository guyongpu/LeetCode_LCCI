//
// Created by yongpu on 2020/2/22.
//

#ifndef LEETCODE_LCCI_P0003_01_TRIPLEINONE_H
#define LEETCODE_LCCI_P0003_01_TRIPLEINONE_H

#include <iostream>

using namespace std;

class P0003_01_TripleInOne {
public:
    int *stack;
    int top[3];
    int stackSize;
    P0003_01_TripleInOne(int stackSize);

    void push(int stackNum, int value);

    int pop(int stackNum);

    int peek(int stackNum);

    bool isEmpty(int stackNum);

    int test();
};


#endif //LEETCODE_LCCI_P0003_01_TRIPLEINONE_H
