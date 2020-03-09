//
// Created by yongpu on 2020/3/9.
//

#include "P0005_02_BianryNumberToString.h"

/**
 * 题目：二进制数转字符串
 * 描述：给定一个介于0和1之间的实数，类型为double，打印它的二进制表达式。如果该数字无法精确地用32位以内的二进制表示，则打印“ERROR”。
 * 思路：将小数部分逐位转化为二进制，当计算次数超过32，则返回ERROR.
 * 备注：仔细处理
 */

string P0005_02_BianryNumberToString::printBin(double num) {
    string result = "0.";
    double data = 1;
    int times = 0;
    while (num) {
        data = data / 2;
        if (num >= data) {
            num = num - data;
            result.push_back('1');
        } else {
            result.push_back('0');
        }
        times++;
        if (times > 32) {
            return "ERROR";
        }
    }
    return result;
}

int P0005_02_BianryNumberToString::test() {
    cout << printBin(0.625) << endl;
    cout << printBin(0.1) << endl;
    return 0;
}
