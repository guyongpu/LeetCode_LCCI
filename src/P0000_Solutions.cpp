//
// Created by yongpu on 2020/2/17.
//

#include "P0000_Solutions.h"

void P0000_Solutions::test(int prob_num) {
    if (prob_num <= 0) {
        cout << "Number error!" << endl;
        return;
    }

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
