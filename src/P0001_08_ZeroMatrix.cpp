//
// Created by yongpu on 2020/2/19.
//

#include "P0001_08_ZeroMatrix.h"
/**
 * 题目：零矩阵
 * 描述：编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零.
 * 思路：法1.将行列用set存储，第二次遍历时清零；法2.用第一行和第一列存储，然后对matrix[0][0]特殊处理.
 * 备注：掌握法1和2
 */

void P0001_08_ZeroMatrix::setZeroes(vector<vector<int>> &matrix) {
    if (matrix.size() == 0) {
        return;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();

    unordered_set<int> rowSet;
    unordered_set<int> colSet;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                rowSet.insert(i);
                colSet.insert(j);
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowSet.find(i) != rowSet.end() || colSet.find(j) != colSet.end()) {
                matrix[i][j] = 0;
            }
        }
    }
}

int P0001_08_ZeroMatrix::test() {
    vector<vector<int> > matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
    };
    setZeroes(matrix);
    return 0;
}
