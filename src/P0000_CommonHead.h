//
// Created by yongpu on 2020/2/17.
//

#ifndef LEETCODE_LCCI_P0000_COMMONHEAD_H
#define LEETCODE_LCCI_P0000_COMMONHEAD_H

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //LEETCODE_LCCI_P0000_COMMONHEAD_H
