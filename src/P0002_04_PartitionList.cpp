//
// Created by yongpu on 2020/2/20.
//

#include "P0002_04_PartitionList.h"

/**
 * 题目：分割链表
 * 描述：编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的 节点之前，内部顺序无要求.
 * 思路：法1.使用两个新链表节点，将两部分分别挂到链表上；法2.使用双指针，符合条件时进行交换.
 * 备注：掌握法1和2
 */

ListNode *P0002_04_PartitionList::partition(ListNode *head, int x) {
    ListNode *head_front = new ListNode(0); // 小于x的节点挂在 head_front 链表上
    ListNode *head_back = new ListNode(0);  // 大于等于x的节点挂在 head_back 链表上

    ListNode *Node = head;
    ListNode *Node_front = head_front;
    ListNode *Node_back = head_back;
    while (Node) {
        if (Node->val < x) {
            Node_front->next = Node;
            Node_front = Node_front->next;
            Node = Node->next;
            Node_front->next = nullptr;
        } else {
            Node_back->next = Node;
            Node_back = Node_back->next;
            Node = Node->next;
            Node_back->next = nullptr;
        }

    }
    // head_front 和 head_back 拼接
    Node_front->next = head_back->next;
    return head_front->next;
}

int P0002_04_PartitionList::test() {
    ListNode *p1 = new ListNode(5);
    ListNode *p2 = new ListNode(7);
    ListNode *p3 = new ListNode(2);
    ListNode *p4 = new ListNode(9);
    ListNode *p5 = new ListNode(3);
    ListNode *p6 = new ListNode(1);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;

    partition(p1,3);
    return 0;
}
