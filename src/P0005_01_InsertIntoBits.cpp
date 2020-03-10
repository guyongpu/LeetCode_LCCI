//
// Created by yongpu on 2020/3/10.
//

#include "P0005_01_InsertIntoBits.h"
#include <bitset>

/**
 * 题目：插入
 * 描述：给定两个32位的整数N与M，以及表示比特位置的i与j.编写一种方法，将M插入N，使得M从N的第j位开始，到第i位结束.
 * 思路：先构造掩码，将N的i-j位置为0，然后通过或运算，使用M替换N的i-j位.
 * 备注：也可以用bitset做，更简单
 */


int P0005_01_InsertIntoBits::insertBits(int N, int M, int i, int j) {
    int len = j - i + 1;
    int mask = 0xFFFFFFFF;

    // 将mask的i--j位置为0
    for (int k = 0; k < len; k++) {
        int step = k + i;
        mask = mask ^ (0x1 << step);
    }
//    cout << "msg1 = " << bitset<32>(N) << endl;
//    cout << "msg2 = " << bitset<32>(mask) << endl;
    // 将N的i-j位位置0
    N = N & mask;
//    cout << "msg3 = " << bitset<32>(N) << endl;
    // 将N的i-j位用M替换
    N = N | (M << i);
//    cout << "msg4 = " << bitset<32>(N) << endl;
    return N;
}

int P0005_01_InsertIntoBits::test() {
    cout << insertBits(1024, 19, 2, 6) << endl;
    return 0;
}
