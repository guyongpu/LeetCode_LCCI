//
// Created by yongpu on 2020/2/20.
//

#include "P0002_02_KthNodeFromEndOfList.h"

/**
 * 题目：返回倒数第 k 个节点
 * 描述：实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值.
 * 思路：双指针法，index_2先走K-1步，然后index_1再走，知道index_2指向最后一个节点，则index_1为结果.
 * 备注：双指针法
 */

int P0002_02_KthNodeFromEndOfList::kthToLast(ListNode *head, int k) {
    if (k <= 0) {
        return 0;
    }
    ListNode *index_1 = head;
    ListNode *index_2 = head;

    // index_2先指向第k个节点
    ListNode *Node = head;
    while (k > 1) {
        Node = Node->next;
        k--;
    }
    index_2 = Node;

    while (index_2->next) {
        index_1 = index_1->next;
        index_2 = index_2->next;
    }

    return index_1->val;
}

int P0002_02_KthNodeFromEndOfList::test() {
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

    cout << kthToLast(p1, 1) << endl;
    cout << kthToLast(p1, 2) << endl;
    cout << kthToLast(p1, 3) << endl;
    cout << kthToLast(p1, 4) << endl;
    cout << kthToLast(p1, 5) << endl;
    cout << kthToLast(p1, 6) << endl;
    return 0;
}
