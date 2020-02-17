//
// Created by yongpu on 2020/2/17.
//

#include "P0001_02_CheckPermutation.h"

/**
 * 题目：判定是否互为字符重排
 * 描述：给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
 * 思路：法1，直接排序后比较；法2，可以通过HashMap的方法比较s1和s2中字符出现次数是否相等。
 * 备注：掌握法1和法2
 */

bool P0001_02_CheckPermutation::CheckPermutation(string s1, string s2) {
    if (s1.length() == s2.length()) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2) {
            return true;
        }
    }
    return false;
}

int P0001_02_CheckPermutation::test() {
    cout << CheckPermutation("abc", "bca") << endl;
    cout << CheckPermutation("abc", "aba") << endl;
    return 0;
}
