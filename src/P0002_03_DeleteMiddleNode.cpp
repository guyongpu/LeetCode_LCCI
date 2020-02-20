//
// Created by yongpu on 2020/2/20.
//

/**
 * 题目：删除中间节点
 * 描述：实现一种算法，删除单向链表中间的某个节点.
 * 思路：使用覆盖值的方法，用后面的值覆盖前面的值.
 * 备注：掌握方法
 */

#include "P0002_03_DeleteMiddleNode.h"

void P0002_03_DeleteMiddleNode::deleteNode(ListNode *node) {
    // 赋值法
    ListNode *Node = node;

    while (Node) {
        // 1-2-3-4-5-6
        if (Node->next) {
            Node->val = Node->next->val;    // 覆盖
            if (Node->next->next) {
                Node = Node->next;
            } else {
                Node->next = nullptr;
                break;
            }
        } else {
            break;
        }
    }

}

int P0002_03_DeleteMiddleNode::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(6);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;

    deleteNode(p4);

    return 0;
}
