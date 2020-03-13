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

// 方法1，递归方法
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

bool P0004_05_LegalBinarySearchTree::isValidBST_1(TreeNode *root) {
    if (root == nullptr) {
        return false;
    }
    bool first_flag = true;
    int value = 0;
    bool result = visit_mid(root, value, first_flag);

    return result;
}

// 方法2,非递归方法进行迭代
bool P0004_05_LegalBinarySearchTree::isValidBST_2(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }
    bool first_flag = true;
    int value = 0;
    stack<TreeNode *> Stk;
    TreeNode *node = root;
    while (!Stk.empty() || node) {
        while (node) {
            Stk.push(node);
            node = node->left;
        }
        if (!Stk.empty()) {
            node = Stk.top();
            // 访问元素
            if (first_flag == true) {
                first_flag = false;
                value = node->val;
            } else {
                if (node->val > value) {
                    value = node->val;
                } else {
                    return false;
                }
            }
            Stk.pop();

            node = node->right;
        }
    }
    return true;
}

// 方法3，采用定义，比较节点的值
bool isValidBST_3_helper(TreeNode *root, TreeNode *father, bool LorR) {
    if (father) {
        //root是左子树
        if (!LorR) {
            if (root->val < father->val) {
                if (root->left) {
                    if (!isValidBST_3_helper(root->left, root, false)) {
                        return false;
                    }
                }
                if (root->right) {
                    if (!isValidBST_3_helper(root->right, root, true)) {
                        return false;
                    }
                }
            }else{
                return false;
            }

        } else {
            if (root->val > father->val) {
                if (root->left) {
                    if (!isValidBST_3_helper(root->left, root, false)) {
                        return false;
                    }
                }
                if (root->right) {
                    if (!isValidBST_3_helper(root->right, root, true)) {
                        return false;
                    }
                }
            }else{
                return false;
            }
        }
    } else {
        if (root->left) {
            if (!isValidBST_3_helper(root->left, root, false)) {
                return false;
            }
        }
        if (root->right) {
            if (!isValidBST_3_helper(root->right, root, true)) {
                return false;
            }
        }
    }
    return true;
}

bool P0004_05_LegalBinarySearchTree::isValidBST_3(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }
    TreeNode *father = nullptr;
    bool LorR = false;
    return isValidBST_3_helper(root, father, LorR);
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

    cout << isValidBST_3(t1) << endl;

    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(1);
    p1->left = p2;
    cout << isValidBST_3(p1) << endl;
    return 0;
}
