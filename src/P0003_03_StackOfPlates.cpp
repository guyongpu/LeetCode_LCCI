//
// Created by yongpu on 2020/2/22.
//

#include "P0003_03_StackOfPlates.h"

/**
 * 题目：堆盘子
 * 描述：堆盘子。设想有一堆盘子，堆太高可能会倒下来。因此，在现实生活中，盘子堆到一定高度时，我们就会另外堆一堆盘子.
 * 思路：设计线性栈，但栈满则添加一个新的栈.
 * 备注：注意细节.
 */

P0003_03_StackOfPlates::P0003_03_StackOfPlates(int cap) {
    cap = 3;
    stack_curr = nullptr;
    capture = cap;
}

void P0003_03_StackOfPlates::push(int val) {
    if (capture == 0) {
        return;
    }
    if (SS.size() != 0 && SS[SS.size() - 1]->size() < capture) {
        SS[SS.size() - 1]->push(val);
        return;
    }

    if (stack_curr == nullptr) {
        stack_curr = new stack<int>;
    }
    if (stack_curr->size() >= capture) {
        SS.push_back(stack_curr);
        stack_curr = new stack<int>;
    }
    stack_curr->push(val);
}

int P0003_03_StackOfPlates::pop() {
    if (capture == 0) {
        return -1;
    }
    if (stack_curr && stack_curr->size() > 0) {
        int val = stack_curr->top();
        stack_curr->pop();
        if (stack_curr->size() == 0) {
            delete stack_curr;
            stack_curr = nullptr;
        }
        return val;
    } else {
        if (SS.size() == 0) {
            return -1;
        }
        stack_curr = SS.back();
        SS.pop_back();
        if (stack_curr->size() <= 0) {
            return -1;
        }
        int val = stack_curr->top();
        stack_curr->pop();
        if (stack_curr->size() == 0) {
            delete stack_curr;
            stack_curr = nullptr;
        }
        return val;
    }
}

int P0003_03_StackOfPlates::popAt(int index) {
    if (capture == 0) {
        return -1;
    }
    int SSsize = SS.size();
    if (index >= SSsize + 1 || index < 0) {
        return -1;
    }

    if (index == SSsize) {
        if (stack_curr && stack_curr->size() > 0) {
            int val = stack_curr->top();
            stack_curr->pop();
            return val;
        } else {
            return -1;
        }
    } else {
        if (SS[index] && SS[index]->size() > 0) {
            int val = SS[index]->top();
            SS[index]->pop();
            if (SS[index]->size() == 0) {
                SS.erase(SS.begin() + index);
            }
            return val;
        } else {
            return -1;
        }
    }
}

int P0003_03_StackOfPlates::test() {
    cout << pop() << ", ";
    cout << popAt(1) << ", ";
    push(1);
    cout << popAt(2) << ", ";
    cout << popAt(2) << ", ";
    cout << pop() << ", ";
    cout << pop() << ", ";
    push(9);
    cout << popAt(3) << ", ";
    cout << pop() << ", ";
    push(51);
    push(20);
    cout << pop() << ", ";
    cout << popAt(2) << ", ";
    cout << popAt(0) << ", ";
    push(35);
    push(1);
    push(19);
    cout << popAt(3) << ", ";
    cout << pop() << ", ";
    cout << pop() << ", ";
    cout << pop() << ", ";
    cout << popAt(1) << ", ";
    cout << pop() << ", ";
    push(36);
    cout << popAt(1) << ", ";
    push(19);
    push(3);
    cout << popAt(3) << ", ";
    push(15);
    push(44);
    cout << pop() << ", ";
    cout << popAt(3) << ", ";
    push(46);
    cout << pop() << ", ";
    cout << popAt(0) << ", ";
    push(42);
    cout << pop() << ", ";
    push(31);
    cout << pop() << ", ";
    cout << popAt(0) << ", ";
    cout << popAt(2) << ", ";
    cout << pop() << ", ";
    push(10);
    push(49);
    cout << pop() << ", ";
    cout << popAt(1) << ", ";
    push(14);
    push(50);
    cout << pop() << ", ";
    cout << pop() << ", ";
    cout << popAt(3) << ", ";
    return 0;
}
