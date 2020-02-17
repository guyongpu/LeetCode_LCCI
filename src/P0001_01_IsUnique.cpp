//
// Created by yongpu on 2020/2/17.
//

#include "P0001_01_IsUnique.h"

/**
 * 题目：判定字符是否唯一
 * 描述：实现一个算法，确定一个字符串 s 的所有字符是否全都不同.
 * 思路：可以使用排序，集合方法做，此处采用排序方法，未使用额外内存.
 * 备注：基础题
 */

bool P0001_01_IsUnique::isUnique(string astr) {
    sort(astr.begin(), astr.end());
    int len = astr.length();
    for (int i = 0; i < len - 1; i++) {
        if (astr[i] == astr[i + 1]) {
            return false;
        }
    }
    return true;
}

int P0001_01_IsUnique::test() {
    cout << isUnique("hello") << endl;
    cout << isUnique("dream") << endl;
    return 0;
}
