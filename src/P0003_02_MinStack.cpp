//
// Created by yongpu on 2020/2/22.
//

#include "P0003_02_MinStack.h"

/**
 * 题目：栈的最小值
 * 描述：请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值.
 * 思路：使用两个vector，一个存储元素，另一个保存最小值，在push和pop的时候需要注意细节.
 * 备注：注意细节.
 */

P0003_02_MinStack::P0003_02_MinStack() {

}

void P0003_02_MinStack::push(int x) {
    arr.push_back(x);
    if (min.size() == 0) {
        min.push_back(x);
    } else {
        if(x <= min.back()){
            min.push_back(x);
        }
    }
}

void P0003_02_MinStack::pop() {
    int top = arr.back();
    arr.pop_back();
    if(top <= min.back()){
        min.pop_back();
    }
}

int P0003_02_MinStack::top() {
    return arr.back();
}

int P0003_02_MinStack::getMin() {
    return min.back();
}

int P0003_02_MinStack::test() {
    return 0;
}
