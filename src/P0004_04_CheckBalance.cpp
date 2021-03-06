//
// Created by yongpu on 2020/3/11.
//

#include "P0004_04_CheckBalance.h"

/**
 * 题目：检查平衡性
 * 描述：实现一个函数，检查二叉树是否平衡.
 * 思路：计算每个节点的左右子树深度，然后递归计算.
 * 备注：要复习这个题
 */

int count_depth(TreeNode *node, int depth) {
    if (node == nullptr) {
        return 0;
    }

    int depth_L = count_depth(node->left, depth + 1);
    int depth_R = count_depth(node->left, depth + 1);

    return max(depth_L, depth_R);
}

bool P0004_04_CheckBalance::isBalanced(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    int left = count_depth(root->left, 0);
    int right = count_depth(root->right, 0);

    if (abs(left - right) > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}


int P0004_04_CheckBalance::test() {
    return 0;
}


