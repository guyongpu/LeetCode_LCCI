//
// Created by yongpu on 2020/3/8.
//

#include "P0005_03_ReverseBits.h"

/**
 * 题目：翻转数位
 * 描述：给定一个32位整数 num，你可以将一个数位从0变为1。请编写一个程序，找出你能够获得的最长的一串1的长度.
 * 思路：将连续的1记录成线段，（起点，终点，长度）,然后再遍历计算，整个过程需要遍历两次.
 * 备注：使用bitset实现.
 */

int P0005_03_ReverseBits::reverseBits(int num) {
    vector<vector<int>> data;

    bitset<32> temp(num);
    for (int i = 0; i < 32;) {
        if (temp[i] == 1) {
            vector<int> record(3, 0);
            record[0] = i;          //起点
            for (int j = i; j < 32; j++) {
                if (temp[j] == 1) {
                    record[1] = j;
                    record[2]++;
                } else {
                    break;
                }
            }
            data.push_back(record);
            i = record[1] + 1;
        } else {
            i++;
        }
    }

    int size = data.size();
    if (size == 0) {
        return 1;
    } else if (size == 1) {
        return data[0][2]+1;
    }
    int maxNum = 0;
    for (int i = 0; i < size - 1; i++) {
        if (data[i][1] + 2 == data[i + 1][0])    // 两段只隔1个0
        {
            maxNum = max(maxNum, data[i][2] + data[i + 1][2]);
        } else {
            int bigger = max(data[i][2], data[i + 1][2]);
            maxNum = max(maxNum, bigger);
        }
    }

    return maxNum+1;
}

int P0005_03_ReverseBits::test() {
    cout << reverseBits(1775) << endl;
    cout << reverseBits(7) << endl;
    return 0;
}
