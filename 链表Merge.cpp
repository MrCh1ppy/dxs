//
// Created by 橙鼠鼠 on 2021.6.13.
//
#include<cstdio>
#include<cstdlib>
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
void MergeList(LinkList La,LinkList Lb,LinkList *Lc);
void input(LinkList *head,LinkList tail);
int main()
{
    LinkList head_a=nullptr, tail = nullptr,head_b=nullptr,head_c=nullptr;
    input(&head_a,tail);
    input(&head_b,tail);
    MergeList(head_a,head_b,&head_c);
    for(LinkList tmp=head_c;tmp;tmp=tmp->next)
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
    for(;p;p=p->next){
        len++;
    }
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
    for(;p&&j<i;p=p->next){
        j++;
    }
    if(!p||j>i){
        return ERROR;
    }
    *e=p->data;
    return OK;
}
Status LocateElem(LinkList L,ElemType e,Status compare(ElemType a,ElemType b))
{
    int j=1;
    for(LinkList p=L;p;p=p->next)
    {
        if(compare(p->data,e)){
            return j;
        }
        ++j;
    }
    return ERROR;
}
Status ListInsert(LinkList *L,int i,ElemType e)
{
    int j=1;
    LinkList p=*L,head=nullptr;
    for(;p&&j<i;p=p->next)
    {
        j++;
        head=p;
    }
    if(j!=i){
        return ERROR;
    }
    LinkList tmp;
    tmp=(LinkList)malloc(sizeof(LNode));
    tmp->data=e;
    tmp->next=p;
    if(head){
        head->next=tmp;
    }
    else{
        *L=tmp;
    }
    return OK;
}
Status ListEmpty(LinkList L)
{
    return !L;
}
void MergeList(LinkList La,LinkList Lb,LinkList *Lc)
{
    int i=1,j=1,k=0;
    int La_len=ListLength(La);
    int Lb_len=ListLength(Lb);
    ElemType ai,bj;
    while(i<=La_len&&j<=Lb_len)          /* 表La和表Lb均非空 */
    {
        GetElem(La,i,&ai);
        GetElem(Lb,j,&bj);
        if(ai<=bj)
        {
            ListInsert(Lc,++k,ai);
            ++i;
        }
        else
        {
            ListInsert(Lc,++k,bj);
            ++j;
        }

    }
    while(i<=La_len)                /* 表La非空且表Lb空 */
    {
        GetElem(La,i,&ai);
        ++i;
        ListInsert(Lc,++k,ai);
    }
    while(j<=Lb_len)                /* 表Lb非空且表La空 */
    {
        GetElem(Lb,j,&bj);
        ++j;
        ListInsert(Lc,++k,bj);
    }
}
void input(LinkList *head,LinkList tail)
{
    int DATA;
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

