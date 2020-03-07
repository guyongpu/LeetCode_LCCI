//
// Created by yongpu on 2020/3/7.
//

#include "P0005_06_ConvertInteger.h"

/**
 * 题目：整数转换
 * 描述：整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。
 * 思路：step1:先对符合进行处理；step2：将AB化为正数；step3：异或，计算结果1的个数
 * 备注：注意对符号位优先处理
 */
int P0005_06_ConvertInteger::convertInteger(int A, int B) {
    int cnt = 0;
    int mask = 0x7FFFFFFF;
    // 如果A和B异号，则cnt =1
    if ((A > 0 && B < 0) || (A < 0 && B > 0)) {
        cnt = 1;
    }
    // 将符号位置为0
    A = A & mask;
    B = B & mask;

    // 对A和B进行异或，在计算结果temp中1的个数
    int temp = A ^B;
    while (temp != 0) {
        temp = (temp - 1) & temp;
        cnt++;
    }
    return cnt;
}

int P0005_06_ConvertInteger::test() {
    cout << convertInteger(29, 15) << endl;
    return 0;
}
