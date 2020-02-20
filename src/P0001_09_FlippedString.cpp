//
// Created by yongpu on 2020/2/19.
//

#include "P0001_09_FlippedString.h"

/**
 * 题目：字符串轮转
 * 描述：字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成.
 * 思路：法1.s1必定包含在s2+s2中，如：s1=xyz,s2=yzx，则s2在xyzxyz中；法2.s1循环模拟旋转，与s2比较.
 * 备注：掌握法1和2
 */

bool P0001_09_FlippedString::isFlipedString(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    string newS2 = s2 + s2;
    if (newS2.find(s1) == newS2.npos) {
        return false;
    }
    return true;
}

int P0001_09_FlippedString::test() {
    cout << isFlipedString("waterbottle", "erbottlewat") << endl;
    return 0;
}
