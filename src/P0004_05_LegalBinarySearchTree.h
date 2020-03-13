//
// Created by yongpu on 2020/3/13.
//

#ifndef LEETCODE_LCCI_P0004_05_LEGALBINARYSEARCHTREE_H
#define LEETCODE_LCCI_P0004_05_LEGALBINARYSEARCHTREE_H

#include <iostream>
#include <stack>
#include "P0000_CommonHead.h"

using namespace std;

class P0004_05_LegalBinarySearchTree {
public:
    bool isValidBST_1(TreeNode *root);
    bool isValidBST_2(TreeNode *root);
    bool isValidBST_3(TreeNode *root);

    int test();
};


#endif //LEETCODE_LCCI_P0004_05_LEGALBINARYSEARCHTREE_H
