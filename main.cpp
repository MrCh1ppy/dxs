#include"TLinkList.h"
#include<iostream>

using namespace std;

int main() {
    TLinkList list1, list2, list3;
    list1.addOneForTest(1, 1);
    list1.addOneForTest(3, 3);
    list1.addOneForTest(2, 2);
    list1.showLinkData();
    list2.addOneForTest(4, 1);
    list2.addOneForTest(1, 3);
    list2.addOneForTest(2, 2);
    list2.showLinkData();
    list3.PolyMul(list1, list2);
    list3.showLinkData();
    return EXIT_SUCCESS;
}

