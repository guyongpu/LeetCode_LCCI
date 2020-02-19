//
// Created by yongpu on 2020/2/19.
//

#include "P0001_07_RotateMatrix.h"

/**
 * 题目：旋转矩阵
 * 描述：给定一幅由N × N矩阵表示的图像，其中每个像素的大小为4字节，编写一种方法，将图像旋转90度.
 * 思路：matrix[i][j]旋转后为matrix[j][n-i]，所以先i,j交换，再左右交换.
 * 备注：掌握分析方法.
 */

void P0001_07_RotateMatrix::rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // 对角交换
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // 左右交换
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(matrix[i][j], matrix[i][n - j-1]);
        }
    }

}

int P0001_07_RotateMatrix::test() {
    vector<vector<int> > matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
    };
    rotate(matrix);
    return 0;
}
