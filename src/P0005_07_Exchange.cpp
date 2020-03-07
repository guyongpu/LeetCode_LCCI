//
// Created by yongpu on 2020/3/7.
//

#include "P0005_07_Exchange.h"

/**
 * 题目：配对交换
 * 描述：配对交换。编写程序，交换某个整数的奇数位和偶数位，尽量使用较少的指令.
 * 思路：使用掩码分别取出奇数位和偶数位，然后奇数位左移，偶数位右移，再或运算，注意偶数位右移后去掉符号位.
 * 备注：注意在右移后去掉符号位.
 */

int P0005_07_Exchange::exchangeBits(int num) {
    int mask_1 = 0x55555555; //取出奇数位的掩码   0b 0101 = 0x5
    int mask_2 = 0xaaaaaaaa; //取出偶数位的掩码    0b 1010 = 0xa

    int num_1 = num & mask_1;   // 奇数位
    int num_2 = num & mask_2;   // 偶数位

    int result = (num_1 << 1) | ((num_2 >> 1) & 0x7FFFFFFF);

    return result;
}

int P0005_07_Exchange::test() {
    cout << exchangeBits(0b01) << endl;
    cout << exchangeBits(2) << endl;
    cout << exchangeBits(1) << endl;
    cout << exchangeBits(3) << endl;
    return 0;
}
