//
// Created by yongpu on 2020/2/21.
//

#include "P0002_06_PalindromeLinkedList.h"

/**
 * 题目：回文链表
 * 描述：编写一个函数，检查输入的链表是否是回文的。
 * 思路：先计算链表长度，然后对后半段进行反转，最后再分别遍历前后半段比较.
 * 备注：掌握方法
 */

bool P0002_06_PalindromeLinkedList::isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    // 计算链表节点数目
    int num = 0;
    ListNode *Node = head;
    while (Node) {
        num++;
        Node = Node->next;
    }

    int cmpcnt = num / 2; //需要比较节点的个数
    int step = (num + 1) / 2;
    //cout << "step = " << step << endl;
    // 先走step步
    Node = head;
    while (step) {
        Node = Node->next;
        step--;
    }
    //cout << "Node->val = " << Node->val << endl;

    // 开始逆序
    ListNode *Node_pre = nullptr;
    ListNode *Node_index = Node;

    while (Node_index) {
        ListNode *temp = Node_index->next;
        // 逆序
        Node_index->next = Node_pre;
        Node_pre = Node_index;
        if (temp) {
            Node_index = temp;
        } else {
            break;
        }
    }
    // 前半段从左到右，后半段从右到左比较，直到后半段指向Nullptr，也可以从cmpcnt计数
    ListNode *Node_left = head;
    ListNode *Node_right = Node_index;
    while (cmpcnt) {
        if (Node_left->val == Node_right->val) {
            Node_left = Node_left->next;
            Node_right = Node_right->next;
        } else {
            return false;
        }
        cmpcnt--;
    }

    return true;
}

int P0002_06_PalindromeLinkedList::test() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(3);
    ListNode *p5 = new ListNode(2);
    ListNode *p6 = new ListNode(1);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;

    cout << isPalindrome(p1) << endl;
    return 0;
}
