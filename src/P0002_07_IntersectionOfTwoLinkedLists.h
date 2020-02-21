//
// Created by yongpu on 2020/2/21.
//

#ifndef LEETCODE_LCCI_P0002_07_INTERSECTIONOFTWOLINKEDLISTS_H
#define LEETCODE_LCCI_P0002_07_INTERSECTIONOFTWOLINKEDLISTS_H

#include <iostream>
#include "P0000_CommonHead.h"

using namespace std;

class P0002_07_IntersectionOfTwoLinkedLists {
public:
    ListNode* getIntersectionNode(int intersectVal, ListNode* listA, ListNode* listB, int skipA, int skipB);
    int test();
};


#endif //LEETCODE_LCCI_P0002_07_INTERSECTIONOFTWOLINKEDLISTS_H
