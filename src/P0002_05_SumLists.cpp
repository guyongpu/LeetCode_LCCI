//
// Created by yongpu on 2020/2/21.
//

#include "P0002_05_SumLists.h"

/**
 * 题目：链表求和
 * 描述：给定两个用链表表示的整数，每个节点包含一个数位，这些数位是反向存放的，也就是个位排在链表首部，编写函数对这两个整数求和，并用链表形式返回结果.
 * 思路：遍历两个链表，将各个节点的值相加即可，注意处理最后的进位.
 * 备注：如果头为最高位，则可以用栈进行处理.
 */
ListNode *P0002_05_SumLists::addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr || l2 == nullptr) {
        if (l1 == nullptr) {
            return l2;
        } else {
            return l1;
        }
    }

    ListNode *Node_1 = l1;
    ListNode *Node_2 = l2;
    auto *newHead = new ListNode(0);
    ListNode *Node_new = newHead;
    int cin = 0;
    int a = 0, b = 0;
    while (Node_1 || Node_2) {
        if (Node_1 && Node_2) {
            a = Node_1->val;
            b = Node_2->val;

            Node_1 = Node_1->next;
            Node_2 = Node_2->next;
        } else if (Node_1) {
            a = Node_1->val;
            b = 0;

            Node_1 = Node_1->next;
        } else {
            a = 0;
            b = Node_2->val;

            Node_2 = Node_2->next;
        }

        int val = a + b + cin;
        cin = val / 10;
        val = val % 10;
        // 建立新节点
        auto *Temp = new ListNode(val);
        Node_new->next = Temp;
        Node_new = Node_new->next;
    }
    if (cin == 1) {
        auto *Temp = new ListNode(cin);
        Node_new->next = Temp;
    }
    return newHead->next;
}

int P0002_05_SumLists::test() {
    ListNode *p1 = new ListNode(7);
    ListNode *p2 = new ListNode(1);
    ListNode *p3 = new ListNode(6);
    ListNode *p4 = new ListNode(5);
    ListNode *p5 = new ListNode(9);
    ListNode *p6 = new ListNode(2);

    p1->next = p2;
    p2->next = p3;

    p4->next = p5;
    p5->next = p6;

    ListNode *head = addTwoNumbers(p1, p4);
    return 0;
}
