//
// Created by yongpu on 2020/2/18.
//

/**
 * 题目：回文排列
 * 描述：给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
 * 思路：法1，采用hash方法，统计每个字符出现的次数；法2，排序后计算每个字符出现的次数是否为偶数，只能出现一次奇数.
 * 备注：掌握法1和法2
 */

#include "P0001_04_PalindromePermutation.h"

bool P0001_04_PalindromePermutation::canPermutePalindrome(string s) {
    int len = s.length();
    sort(s.begin(), s.end());

    int unique = 0;
    for (int i = 0; i < len;) {
        int count = 1;
        char c = s[i];
        int pos = i + 1;
        while (pos < len) {
            if (c == s[pos]) {
                pos++;
                count++;
            } else {
                break;
            }
        }
        i = pos;
        if (count % 2 == 0) {
            continue;
        } else {
            if (unique == 1) {
                return false;
            } else {
                unique++;
            }
        }
    }
    return true;
}

int P0001_04_PalindromePermutation::test() {

    cout << canPermutePalindrome("heoel") << endl;      // 0
    cout << canPermutePalindrome("heooell") << endl;    // 1
    cout << canPermutePalindrome("heooelql") << endl;   // 0
    cout << canPermutePalindrome("heoooehol") << endl;  // 1

}