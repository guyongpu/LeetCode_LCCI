//
// Created by yongpu on 2020/2/17.
//

#include "P0000_Solutions.h"

void P0000_Solutions::test(int prob_num) {
    if (prob_num <= 0) {
        cout << "Number error!" << endl;
        return;
    }
    prob_num = 7;
    switch (prob_num) {
        case 1:
            run(new P0001_01_IsUnique());
            break;
        case 2:
            run(new P0001_02_CheckPermutation());
            break;
        case 3:
            run(new P0001_03_String_to_URL_LCCI());
            break;
        case 4:
            run(new P0001_04_PalindromePermutation());
            break;
        case 5:
            run(new P0001_05_OneAway());
            break;
        case 6:
            run(new P0001_06_CompressString());
            break;
        case 7:
            run(new P0001_07_RotateMatrix());
            break;
        default:
            cout << "Number not find! " << endl;
            break;


    }
}

// 采用函数参数模板，可以使代码更加简洁
template<typename T>
void run(T pobj) {
    pobj->test();

}
