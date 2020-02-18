//
// Created by yongpu on 2020/2/18.
//

#include "P0001_06_CompressString.h"

/**
 * 题目：字符串压缩
 * 描述：字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能，若“压缩”后的字符串没有变短，则返回原先的字符串。
 * 思路：一次遍历，顺序计算字符出现的次数，最后比较压缩前后的长度。
 * 备注：要仔细些.
 */

string P0001_06_CompressString::compressString(string S) {
    int len = S.length();
    string str;
    for (int i = 0; i < len;) {
        str.append(S, i, 1);

        int count = 1;
        char c = S[i];
        int index = i + 1;
        while (index < len) {
            if (c == S[index]) {
                index++;
                count++;
            } else {
                break;
            }
        }
        i = index;
        str.append(to_string(count));
    }
    if(str.length() >= len){
        return S;
    }

    return str;
}

int P0001_06_CompressString::test() {
    cout << compressString("aabcccccaaa") << endl;
    cout << compressString("abbccd") << endl;

    return 0;
}
