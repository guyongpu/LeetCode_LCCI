//
// Created by yongpu on 2020/2/20.
//

#include "P0002_01_RemoveDuplicateNode.h"

/**
 * 题目：移除重复节点
 * 描述：移除未排序链表中的重复节点。保留最开始出现的节点.
 * 思路：法1，使用set或者数组标记节点是否出现，再保留不重复节点；法2.检查每个节点是否出现，然后删除重复节点.
 * 备注：法1.节省时间；法2.节省空间
 */

ListNode *P0002_01_RemoveDuplicateNode::removeDuplicateNodes(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *pNode_index = head;       // 已检查完成的节点
    ListNode *pNode_next = head->next;  // 待检查的节点

    while (pNode_next) {
        ListNode *pNode = head;

        // 检测pNode_next是否在[head,pNode_index]中出现过
        bool ExistFlag = false;
        while (pNode && pNode != pNode_next) {
            if (pNode->val == pNode_next->val) {
                pNode_index->next = pNode_next->next;
                ExistFlag = true;
                break;
            } else {
                pNode = pNode->next;
            }
        }

        if (!ExistFlag) { // 未出现过
            pNode_index = pNode_next;   // 指针往右移动
        }
        pNode_next = pNode_next->next;  // 待检查节点
    }

    return head;
}

int P0002_01_RemoveDuplicateNode::test() {
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

    ListNode *head = removeDuplicateNodes(p1);
    return 0;
}
