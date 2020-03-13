//
// Created by yongpu on 2020/3/13.
//

#include "P0004_05_LegalBinarySearchTree.h"

/**
 * 题目：合法二叉搜索树
 * 描述：实现一个函数，检查一棵二叉树是否为二叉搜索树.
 * 思路：法1，使用递归中序遍历；法2，使用迭代中序遍历；法3，直接比较left<root>right，且父节点满足要求.
 * 备注：掌握三种方法.
 */
bool visit_mid(TreeNode *root, int &value, bool &first_flag) {
    bool result = true;

    // 遍历左子树
    if (root->left) {
        result = visit_mid(root->left, value, first_flag);
        if (result == false) {
            return false;
        }
    }

    // 处理元素
    if (first_flag) {   // 首元素
        first_flag = false;
        value = root->val;
    } else {
        // 其余元素要求升序，即  前 < 后
        if (value >= root->val) {
            return false;
        }
        value = root->val;
    }

    // 遍历右子树
    if (root->right) {
        result = visit_mid(root->right, value, first_flag);
        if (result == false) {
            return false;
        }
    }
    return result;
}

bool P0004_05_LegalBinarySearchTree::isValidBST(TreeNode *root) {
    if (root == nullptr) {
        return false;
    }
    bool first_flag = true;
    int value = 0;
    bool result = visit_mid(root, value, first_flag);

    return result;
}

int P0004_05_LegalBinarySearchTree::test() {
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(4);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(6);


    t1->left = t2;
    t1->right = t3;

    t3->left = t4;
    t3->right = t5;

    cout << isValidBST(t1) << endl;

    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(1);
    p1->left = p2;
    cout << isValidBST(p1) << endl;
    return 0;
}
