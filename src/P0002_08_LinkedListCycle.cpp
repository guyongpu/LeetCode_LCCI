//
// Created by yongpu on 2020/2/21.
//

#include "P0002_08_LinkedListCycle.h"

/**
 * 题目：环路检测
 * 描述：给定一个有环链表，实现一个算法返回环路的开头节点.
 * 思路：快慢指针，1.快指针每次2步，慢指针每次1步，最后step步后相遇则有环;2.快指针先走step步，然后一起走，第一次相遇则为入口节点.
 * 备注：注意细节.
 */

ListNode *P0002_08_LinkedListCycle::detectCycle(ListNode *head, int pos) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode *Node_low = head->next;
    ListNode *Node_fast = head->next->next;

    int step = 1;
    bool exist = false;
    while (Node_low && Node_fast) {
        if (Node_low == Node_fast) {
            exist = true;
            break;
        } else {
            Node_low = Node_low->next;
            step++;
            if (Node_fast->next) {
                Node_fast = Node_fast->next->next;
            } else {
                break;
            }
        }
    }
    if (!exist) {
        return nullptr;
    }

    cout << step << endl;

    Node_fast = head;
    while (step) {
        Node_fast = Node_fast->next;
        step--;
    }

    Node_low = head;
    while (Node_low && Node_fast) {
        if (Node_low == Node_fast) {
            return Node_low;
        }
        Node_low = Node_low->next;
        Node_fast = Node_fast->next;
    }

    return nullptr;
}

int P0002_08_LinkedListCycle::test() {
    ListNode *p1 = new ListNode(7);
    ListNode *p2 = new ListNode(1);
    ListNode *p3 = new ListNode(6);
    ListNode *p4 = new ListNode(5);
    ListNode *p5 = new ListNode(9);
    ListNode *p6 = new ListNode(2);
    ListNode *p7 = new ListNode(10);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;

    p7->next = p1;

    ListNode *head = detectCycle(p1, 0);

    cout << head->val << endl;
    return 0;
}
