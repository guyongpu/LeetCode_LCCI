//
// Created by yongpu on 2020/2/18.
//

#include "P0001_05_OneAway.h"

/**
 * 题目：一次编辑
 * 描述：字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
 * 思路：先判断是否相等，再判断长度，情况1，长度相等则替换一个，情况2，不相等则双指针操作,替换一个.
 * 备注：注意细节.
 */
bool P0001_05_OneAway::oneEditAway(string first, string second) {
    if (first == second) {
        return true;
    }

    int len1 = first.length();
    int len2 = second.length();
    if (abs(len1 - len2) > 1) {
        return false;
    }

    if (len1 == len2) { // 替换
        int uniqueCount = 0;
        for (int i = 0; i < len1; i++) {
            if (first[i] == second[i]) {
                continue;
            } else {
                uniqueCount++;
            }
            if (uniqueCount > 1) {
                return false;
            }
        }
    } else {
        if (len1 < len2) {
            swap(first, second);
            swap(len1, len2);
        }
        // first 长，first删除一个字符等价于second插入一个
        int index1 = 0, index2 = 0;
        int uniqueCount = 0;
        while (index1 < len1) {
            if (first[index1] == second[index2]) {
                index1++, index2++;
            } else {
                uniqueCount++;
                if (uniqueCount > 1) {
                    return false;
                }
                index1++;
            }
        }
    }
    return true;
}

int P0001_05_OneAway::test() {
    cout << oneEditAway("pale", "ple") << endl;
    cout << oneEditAway("pales", "pal") << endl;
    return 0;
}
