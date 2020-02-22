//
// Created by yongpu on 2020/2/22.
//

#include "P0003_01_TripleInOne.h"

/**
 * 题目：三合一
 * 描述：三合一。描述如何只用一个数组来实现三个栈.
 * 思路：定义stackSize,stack,top三个变量，实现栈的操作，top记录栈的元素个数，stack为数组，前中后三段.
 * 备注：注意细节即可.
 */

P0003_01_TripleInOne::P0003_01_TripleInOne(int stackSize) {
    this->stackSize = stackSize;
    stack = new int[stackSize * 3];
    top[0] = top[1] = top[2] = 0;   // 记录栈的元素个数
}

void P0003_01_TripleInOne::push(int stackNum, int value) {
    if (top[stackNum] < stackSize) {
        int index = stackSize * stackNum + top[stackNum];
        stack[index] = value;
        top[stackNum]++;
    }
}

int P0003_01_TripleInOne::pop(int stackNum) {
    if (top[stackNum] != 0) {
        int index = stackNum * stackSize + top[stackNum] - 1;
        top[stackNum]--;
        return stack[index];
    } else {
        return -1;
    }
}

int P0003_01_TripleInOne::peek(int stackNum) {  // 栈顶元素
    if (top[stackNum] != 0) {
        int index = stackNum * stackSize + top[stackNum] - 1;
        return stack[index];
    } else {
        return -1;
    }
}

bool P0003_01_TripleInOne::isEmpty(int stackNum) {
    return top[stackNum] == 0;
}

int P0003_01_TripleInOne::test() {
    push(0, 1);
    push(0, 2);
    push(0, 3);
    cout << pop(0) << endl;
    cout << pop(0) << endl;
    cout << pop(0) << endl;
    cout << peek(0) << endl;
    return 0;
}
