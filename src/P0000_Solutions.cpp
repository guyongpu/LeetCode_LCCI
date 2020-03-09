//
// Created by yongpu on 2020/2/17.
//

#include "P0000_Solutions.h"

void P0000_Solutions::test(string str_num) {
    if (str_num == "P0001_01_IsUnique") {
        run(new P0001_01_IsUnique());
    } else if (str_num == "P0001_02_CheckPermutation") {
        run(new P0001_02_CheckPermutation());
    } else if (str_num == "P0001_03_String_to_URL_LCCI") {
        run(new P0001_03_String_to_URL_LCCI());
    } else if (str_num == "P0001_04_PalindromePermutation") {
        run(new P0001_04_PalindromePermutation());
    } else if (str_num == "P0001_05_OneAway") {
        run(new P0001_05_OneAway());
    } else if (str_num == "P0001_06_CompressString") {
        run(new P0001_06_CompressString());
    } else if (str_num == "P0001_07_RotateMatrix") {
        run(new P0001_07_RotateMatrix());
    } else if (str_num == "P0001_08_ZeroMatrix") {
        run(new P0001_08_ZeroMatrix());
    } else if (str_num == "P0001_09_FlippedString") {
        run(new P0001_09_FlippedString());
    } else if (str_num == "P0002_01_RemoveDuplicateNode") {
        run(new P0002_01_RemoveDuplicateNode());
    } else if (str_num == "P0002_02_KthNodeFromEndOfList") {
        run(new P0002_02_KthNodeFromEndOfList());
    } else if (str_num == "P0002_03_DeleteMiddleNode") {
        run(new P0002_03_DeleteMiddleNode());
    } else if (str_num == "P0002_04_PartitionList") {
        run(new P0002_04_PartitionList());
    } else if (str_num == "P0002_05_SumLists") {
        run(new P0002_05_SumLists());
    } else if (str_num == "P0002_06_PalindromeLinkedList") {
        run(new P0002_06_PalindromeLinkedList());
    } else if (str_num == "P0002_07_IntersectionOfTwoLinkedLists") {
        run(new P0002_07_IntersectionOfTwoLinkedLists());
    } else if (str_num == "P0002_08_LinkedListCycle") {
        run(new P0002_08_LinkedListCycle());
    } else if (str_num == "P0003_01_TripleInOne") {
        run(new P0003_01_TripleInOne(2));
    } else if (str_num == "P0003_02_MinStack") {
        run(new P0003_02_MinStack());
    } else if (str_num == "P0003_03_StackOfPlates") {
        run(new P0003_03_StackOfPlates(1));
    } else if (str_num == "P0005_02_BianryNumberToString") {
        run(new P0005_02_BianryNumberToString());
    } else if (str_num == "P0005_03_ReverseBits") {
        run(new P0005_03_ReverseBits());
    } else if (str_num == "P0005_04_ClosedNumber") {
        run(new P0005_04_ClosedNumber());
    } else if (str_num == "P0005_06_ConvertInteger") {
        run(new P0005_06_ConvertInteger());
    } else if (str_num == "P0005_07_Exchange") {
        run(new P0005_07_Exchange());
    } else {
        cout << "Number not find! " <<
             endl;
    }
}

// 采用函数参数模板，可以使代码更加简洁
template<typename T>
void run(T pobj) {
    pobj->test();
}
