//
// Created by yongpu on 2020/2/21.
//

#include "P0002_07_IntersectionOfTwoLinkedLists.h"

/**
 * 题目：链表相交
 * 描述：给定两个（单向）链表，判定它们是否相交并返回交点.
 * 思路：使用快慢指针，先计算长度，然后长的先走dif步，再一起遍历比较.
 * 备注：注意细节.
 */

ListNode *P0002_07_IntersectionOfTwoLinkedLists::getIntersectionNode(int intersectVal, ListNode *listA, ListNode *listB,
                                                                     int skipA, int skipB) {
    if (listA == nullptr || listB == nullptr) {
        return nullptr;
    }
    ListNode *Node_A = listA;
    ListNode *Node_B = listB;

    int num_A = 0;
    while (Node_A) {
        Node_A = Node_A->next;
        num_A++;
    }

    int num_B = 0;
    while (Node_B) {
        Node_B = Node_B->next;
        num_B++;
    }

    Node_A = listA;
    Node_B = listB;
    int dif = abs(num_A - num_B);
    if (num_A > num_B) {
        while (dif) {
            Node_A = Node_A->next;
            dif--;
        }
    } else {
        while (dif) {
            Node_B = Node_B->next;
            dif--;
        }
    }

    // 开始一起遍历
    while (Node_A && Node_B) {
        if (Node_A == Node_B) {
            return Node_A;
        } else {
            Node_A = Node_A->next;
            Node_B = Node_B->next;
        }
    }
    return nullptr;
}

int P0002_07_IntersectionOfTwoLinkedLists::test() {
    ListNode *p0 = new ListNode(0);
    ListNode *p1 = new ListNode(7);
    ListNode *p2 = new ListNode(1);
    ListNode *p3 = new ListNode(6);

    ListNode *p4 = new ListNode(5);
    ListNode *p5 = new ListNode(9);


    ListNode *px1 = new ListNode(12);
    ListNode *px2 = new ListNode(9);

    p0->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = px1;

    p4->next = p5;
    p5->next = px1;


    px1->next = px2;

    ListNode *node = getIntersectionNode(0, p1, p4, 0, 0);
    cout << node->val << endl;
    return 0;
}
