//
// Created by yongpu on 2020/2/17.
//

#include "P0001_03_String_to_URL_LCCI.h"

/**
 * 题目：URL化
 * 描述：URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。
 * 思路：在原数组上进行操作，由少变多，从后开始遍历，双指针法，先计算newLength，再遍历替换。
 * 备注：在末位要加上'\0'，C++11标准。
 */

string P0001_03_String_to_URL_LCCI::replaceSpaces(string S, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (S[i] == ' ') {
            count++;
        }
    }
    int newLength = length + 2 * count;

    int index = newLength - 1;
    for (int i = length - 1; i >= 0; i--) {
        if (S[i] == ' ') {
            S[index] = '0';
            S[index - 1] = '2';
            S[index - 2] = '%';
            index = index - 3;
        } else {
            S[index] = S[i];
            index = index - 1;
        }
    }
    S[newLength] = '\0';
    return S;
}

#include <cstring>

int P0001_03_String_to_URL_LCCI::test() {
    cout << replaceSpaces("Mr John Smith    ", 13) << endl;
    return 0;
}
