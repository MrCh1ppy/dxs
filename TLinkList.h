//
// Created by 橙鼠鼠 on 2021.6.13.
//

#ifndef DXS_TLINKLIST_H
#define DXS_TLINKLIST_H


class TLinkList {
private:
    typedef struct linkListNode {
        int coe;//系数:coeffcient
        int ind;//指数:index
        linkListNode *next;//记录下一个节点的地址
        linkListNode *pre;//前一个节点的地址
    } NODE;

    //添加节点
    void addNode(NODE target);

    void addNode(int coe, int ind);

    //比较两个节点的值
    int compare(NODE a, NODE b);

    //节点构造函数
    inline NODE getNode(int coe, int ind);

    //节点相乘函数
    inline NODE nodeMul(NODE a, NODE b);

    //赋值函数,a将获得b的值
    inline void giveValue(TLinkList b);

public:
    NODE *head;//记录头节点的地址
    NODE *tail;//记录最后一个非null的节点
    //构造函数
    TLinkList();

    //浏览链表的内容
    void showLinkData();

    //增加一个节点
    void addOneForTest(int coe, int ind);

    //多项式相加
    void PolyAdd(TLinkList a, TLinkList b);

    //多项式相乘
    void PolyMul(TLinkList a, TLinkList b);

    //多项式相减
    void PolyCut(TLinkList a, TLinkList b);
};


#endif //DXS_TLINKLIST_H
