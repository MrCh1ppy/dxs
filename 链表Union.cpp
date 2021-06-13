//
// Created by 橙鼠鼠 on 2021.6.13.
//

#include <cstdio>
#include <cstdlib>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct  L
{
    ElemType data;
    struct L *next;
}LNode;
typedef LNode *LinkList;
Status equal(ElemType a,ElemType b);
int ListLength(LinkList L);
Status GetElem(LinkList L,int i,ElemType *e);
Status LocateElem(LinkList L,ElemType e,Status compare(ElemType a,ElemType b));
Status ListInsert(LinkList *L,int i,ElemType e);
Status ListEmpty(LinkList L);
void Union(LinkList *La,LinkList Lb);
void input(LinkList *head);
int main()
{
    LinkList head_a=nullptr,head_b=nullptr;
    input(&head_a);
    input(&head_b);
    Union(&head_a,head_b);
    for(LinkList tmp=head_a;tmp;tmp=tmp->next)
        printf("%d ",tmp->data);
    printf("\n");
    return 0;
}
int ListLength(LinkList L)
{
    if(L==nullptr)
        return 0;
    int len=0;
    LinkList p=L;
    for(;p;p=p->next)
        ++len;
    return len;
}
Status equal(ElemType a,ElemType b)
{
    return a == b;
}
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j=1;
    LinkList p=L;
    for(;p&&j<i;p=p->next)
        j++;
    if(!p||j>i)
        return ERROR;
    *e=p->data;
    return OK;
}
Status LocateElem(LinkList L,ElemType e,Status compare(ElemType a,ElemType b))
{
    int j=1;
    for(LinkList p=L;p;p=p->next)
    {
        if(compare(p->data,e))
            return j;
        ++j;
    }
    return ERROR;
}
Status ListInsert(LinkList *L,int i,ElemType e)
{
    int j=1;
    LinkList head=nullptr,p=*L;//循环之后分别是第i位置的前后两个结点
    for(;p&&j<i;p=p->next)//向后迭代
    {
        j++;
        head=p;
    }
    if(j!=i)//如果不能到达i位置
        return ERROR;//返回错误
    LinkList tmp;//开辟新结点
    tmp=(LinkList)malloc(sizeof(LNode));
    tmp->data=e;
    tmp->next=p;//新结点指向后一个结点
    if(head)
        head->next=tmp;//前一个结点指向新结点
    else
        *L=tmp;//tmp作为头结点
    return OK;
}
Status ListEmpty(LinkList L)
{
    return !L;
}
void Union(LinkList *La,LinkList Lb)
{
    ElemType e;
    int La_len,Lb_len;
    int i;
    La_len=ListLength(*La);
    Lb_len=ListLength(Lb);
    for(i=1;i<=Lb_len;++i)
    {
        GetElem(Lb,i,&e); /* 取Lb中第i个数据元素赋给e */
        if(!LocateElem(*La,e,equal)) /* La中不存在和e相同的元素,则插入之 */
            ListInsert(La,++La_len,e);
    }
}
void input(LinkList *head)
{
    int DATA;
    LinkList tail;
    while(1)
    {
        scanf("%d",&DATA);
        if(DATA == -1)
            break;
        LinkList tmp;
        tmp=(LinkList)malloc(sizeof(LNode));
        tmp->data=DATA;
        tmp->next=nullptr;
        if(!*head)
        {
            *head=tmp;
            tail=tmp;
        }
        else
        {
            tail->next=tmp;
            tail=tmp;
        }
    }
}