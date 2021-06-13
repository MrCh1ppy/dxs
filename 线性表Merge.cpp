//
// Created by 橙鼠鼠 on 2021.6.13.
//
#include<cstdio>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
//Status 为函数的类型，其值是函数结果状态代码，如OK等
typedef int Status;
// ElemType为数据元素类型，根据实际情况而定，这里假设为int
typedef int ElemType;
#define MAXSIZE 50          /* 存储空间初始分配量 */
typedef struct
{
    ElemType data[MAXSIZE];  /* 数组，存储数据元素 */
    int length;              /* 表当前有效长度 */
}SqList;
int ListLength(SqList L)
{
    return L.length;
}
Status equal(ElemType a,ElemType b)
{
    return a == b;
}
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length){
        return ERROR;
    }
    *e=L.data[i-1];
    return OK;
}
Status LocateElem(SqList L,ElemType e,Status compare(ElemType a,ElemType b))
{
    for(int i=0;i<L.length;++i)
    {
        if(compare(L.data[i],e)){
            return i+1;
        }
    }
    return ERROR;
}
Status ListInsert(SqList *L,int i,ElemType e)
{
    if(i<1 || i>ListLength(*L)+1 || i>=MAXSIZE){
        return ERROR;
    }
    for(int j=L->length;j>=i;--j)
    {
        L->data[j]=L->data[j-1];
    }
    L->data[i-1]=e;
    ++L->length;
    return OK;
}
Status ListEmpty(SqList L)
{
    return L.length?FALSE:TRUE;
}
void MergeList(SqList La,SqList Lb,SqList &Lc)
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
            ListInsert(&Lc,++k,ai);
            ++i;
        }
        else
        {
            ListInsert(&Lc,++k,bj);
            ++j;
        }
    }
    while(i<=La_len)                /* 表La非空且表Lb空 */
    {
        GetElem(La,i++,&ai);
        ListInsert(&Lc,++k,ai);
    }
    while(j<=Lb_len)                /* 表Lb非空且表La空 */
    {
        GetElem(Lb,j++,&bj);
        ListInsert(&Lc,++k,bj);
    }
}
int main()
{
    SqList a,b,c;
    int la,lb;
    scanf("%d %d",&la,&lb);
    for(int i=0;i<la;++i){
        scanf("%d",&a.data[i]);
    }
    a.length=la;
    for(int i=0;i<lb;++i){
        scanf("%d",&b.data[i]);
    }
    b.length=lb;
    c.length=0;
    MergeList(a,b,c);
    for(int i=0;i<c.length;++i){
        printf("%d ",c.data[i]);
    }
    printf("\n");
    return 0;
}
