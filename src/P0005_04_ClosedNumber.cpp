//
// Created by yongpu on 2020/3/8.
//

#include "P0005_04_ClosedNumber.h"

/**
 * 题目：下一个数
 * 描述：下一个数。给定一个正整数，找出与其二进制表达式中1的个数相同且大小最接近的那两个数（一个略大，一个略小）.
 * 思路：大数，将01转化为10，并将低位的1移到最右侧；小数，将10转化为01，并将低位的1移到最左侧.
 * 备注：使用bitset，数据的低位在左边
 */


vector<int> P0005_04_ClosedNumber::findClosedNumbers(int num) {
    bitset<32> small(num);
    bitset<32> bigger(num);
    int s = -1;
    // small, 10 转 01，1移到左侧
    for (int i = 1; i < 32; i++) {
        if (small[i] == 1 && small[i - 1] == 0) {
            // 取反
            small.flip(i);
            small.flip(i - 1);
            for (int left = 0, right = i - 2; left < right;) {
                while (left < right && small[left] == 0) left++;
                while (left < right && small[right] == 1) right--;
                small.flip(left);
                small.flip(right);
            }
            s = (int)small.to_ulong();
            break;
        }
    }

    // bigger, 01转10，1移到最右侧
    int b = -1;
    for (int i = 1; i < 32; i++) {
        if (bigger[i] == 0 && bigger[i - 1] == 1) {
            bigger.flip(i);
            bigger.flip(i - 1);

            for (int left = 0, right = i - 2; left < right;) {
                while (left < right && bigger[left] == 1) left++;
                while (left < right && bigger[right] == 0) right--;
                bigger.flip(left);
                bigger.flip(right);
            }
            b = (int)bigger.to_ulong();
            break;
        }
    }
    return {b,s};

}

int P0005_04_ClosedNumber::test() {
    bitset<32> num(13);

    vector<int> result;
    result = findClosedNumbers(3);
    result = findClosedNumbers(0b10100);
    result = findClosedNumbers(2);
    result = findClosedNumbers(1);
    return 0;
}
