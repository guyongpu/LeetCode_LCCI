//
// Created by yongpu on 2020/2/22.
//

#include "P0003_03_StackOfPlates.h"

P0003_03_StackOfPlates::P0003_03_StackOfPlates(int cap) {
    cap = 3;
    stack_curr = nullptr;
    capture = cap;
}

void P0003_03_StackOfPlates::push(int val) {
    if (capture == 0) {
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
    if(capture == 0){
        return -1;
    }
    int SSsize = SS.size();
    if (index >= SSsize + 1 || index < 0) {
        return -1;
    }

    if (index == SSsize) {
        if (stack_curr&& stack_curr->size() > 0) {
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
    pop();popAt(1);push(1);popAt(2);popAt(2);
    pop();pop();push(9);popAt(3);pop();
    push(51);push(20);pop();popAt(2);popAt(0);push(35);push(1);push(19);popAt(3);pop();pop();pop();
    popAt(1);pop();push(36);popAt(1);push(19);push(3);popAt(3);push(15);push(44);pop();
    popAt(3);push(46);pop();popAt(0);push(42);pop();push(31);pop();popAt(0);popAt(2);pop();push(10);push(49);pop();popAt(1);push(14);push(50);pop();pop();popAt(3);
    return 0;
}
