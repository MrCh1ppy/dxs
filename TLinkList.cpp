//
// Created by 橙鼠鼠 on 2021.6.13.
//

#include "TLinkList.h"
#include <iostream>

using namespace std;

TLinkList::TLinkList() {
    this->head = new NODE;
    this->head->coe = -100;
    this->head->ind = -86;
    this->head->pre = nullptr;
    this->tail = head;
    this->head->next = nullptr;
}

int TLinkList::compare(NODE a, NODE b) {
    if (a.ind > b.ind) {
        return 1;
    } else if (a.ind == b.ind) {
        return 0;
    } else {
        return -1;
    }
}

void TLinkList::addNode(NODE target) {
    NODE *cur;//比较两个节点的值
    if (target.coe == 0) {//如果系数为0
        return;
    }
    //寻找的目标是待插入节点位置的前一个
    for (cur = head; cur->next != nullptr && compare(target, *(cur->next)) > 0; cur = cur->next);
    if (cur == tail) {//如果没有符合要求的节点位置
        NODE *temp = new NODE;
        *temp = getNode(target.coe, target.ind);
        temp->pre = tail;
        tail->next = temp;
        tail = temp;
    } else if (cur->next->ind == target.ind) {
        NODE *tempTarget = cur->next;
        tempTarget->coe += target.coe;
        if (tempTarget->coe == 0) {//完成后的节点次数为0则进行删除操作
            cout << "系数为0,删除" << endl;
            tempTarget->pre->next = tempTarget->next;
            if (tempTarget->next != nullptr) {
                tempTarget->next->pre = tempTarget->pre;
            }
            delete (tempTarget);
        }
    } else if (target.ind > cur->ind) {//如果找到目标位置,且该次数未出现
        NODE *tempNode = new NODE;
        *tempNode = getNode(target.coe, target.ind);
        tempNode->pre = cur;
        tempNode->next = cur->next;
        cur->next = tempNode;
        tempNode->next->pre = tempNode;
    } else {
        cout << "ERROR" << endl;
    }
}

void TLinkList::addNode(int coe, int ind) {
    NODE temp = getNode(coe, ind);
    addNode(temp);
}

void TLinkList::showLinkData() {
    NODE *cur = nullptr;
    if (head->next == nullptr) {
        cout << "\a为空" << endl;
    }
    for (cur = head->next; cur != nullptr; cur = cur->next) {
        if (cur != head->next) {
            cout << " + ";
        }
        cout << cur->coe << "X^" << cur->ind;
    }
    cout << endl;
}

void TLinkList::addOneForTest(int coe, int ind) {
    addNode(coe, ind);
}

void TLinkList::PolyAdd(TLinkList a, TLinkList b) {
    auto *result = new TLinkList;
    NODE *cur;
    for (cur = a.head->next; cur != nullptr; cur = cur->next) {
        result->addNode(*cur);
    }
    for (cur = b.head->next; cur != nullptr; cur = cur->next) {
        result->addNode(*cur);
    }
    this->giveValue(*result);
}

inline TLinkList::NODE TLinkList::nodeMul(NODE a, NODE b) {
    int coe = a.coe * b.coe;
    int ind = a.ind + b.ind;
    return getNode(coe, ind);
}

inline TLinkList::NODE TLinkList::getNode(int coe, int ind) {
    NODE temp;
    temp.pre = nullptr;
    temp.next = nullptr;
    temp.ind = ind;
    temp.coe = coe;
    return temp;
}

void TLinkList::PolyMul(TLinkList a, TLinkList b) {
    NODE *curI, *curJ;
    auto *result = new TLinkList;
    for (curI = a.head->next; curI != nullptr; curI = curI->next) {
        for (curJ = b.head->next; curJ != nullptr; curJ = curJ->next) {
            NODE temp = nodeMul(*curI, *curJ);
            result->addNode(temp);
        }
    }
    this->giveValue(*result);
}

void TLinkList::PolyCut(TLinkList a, TLinkList b) {
    auto *result = new TLinkList;
    NODE *cur;
    for (cur = a.head->next; cur != nullptr; cur = cur->next) {
        NODE temp = *cur;
        temp.coe = -1 * temp.coe;
        result->addNode(*cur);
    }
    for (cur = b.head->next; cur != nullptr; cur = cur->next) {
        NODE temp = *cur;
        temp.coe = -1 * temp.coe;
        result->addNode(*cur);
    }
    this->giveValue(*result);
}

inline void TLinkList::giveValue(TLinkList b) {
    this->head = b.head;
    this->tail = b.tail;
}