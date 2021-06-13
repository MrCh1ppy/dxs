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
Status equal(ElemType a,ElemType b);
int ListLength(SqList L);
Status GetElem(SqList L,int i,ElemType *e);
int LocateElem(SqList L,ElemType e,Status compare(ElemType a,ElemType b));
Status ListInsert(SqList *L,int i,ElemType e);
Status ListEmpty(SqList L);
void Union(SqList *La,SqList Lb);
void input(SqList *a);
int main()
{
    SqList a,b;
    input(&a);
    input(&b);
    Union(&a,b);
    for(int i=0;i<a.length;++i){
        printf("%d ",a.data[i]);
    }
    printf("\n");
    return 0;
}
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
int LocateElem(SqList L,ElemType e,Status compare(ElemType a,ElemType b))
{
    for(int i=0;i<L.length;++i)//循环迭代
    {
        if(compare(L.data[i],e)){
            return i+1;//返回位序
        }//找到第一个符合条件的
    }
    return ERROR;//返回错误
}
Status ListInsert(SqList *L,int i,ElemType e)
{
    if(i<1 || i>ListLength(*L)+1 || i>=MAXSIZE)//安全性检查
        return ERROR;
    for(int j=L->length;j>=i;--j){
        L->data[j]=L->data[j-1];
    }//把i位置之后的数据向后移一位
    L->data[i-1]=e;//在i位置插入e
    ++L->length;//长度加一
    return OK;
}
Status ListEmpty(SqList L)
{
    return L.length?FALSE:TRUE;
}
void Union(SqList *La,SqList Lb)
{
    ElemType e;
    int La_len,Lb_len;
    int i;
    La_len=ListLength(*La);
    Lb_len=ListLength(Lb);
    for(i=1;i<=Lb_len;++i)
    {
        GetElem(Lb,i,&e); /* 取Lb中第i个数据元素赋给e */
        if(!LocateElem(*La,e,equal)){
            ListInsert(La,++La_len,e);
        } /* La中不存在和e相同的元素,则插入之 */
    }
}
void input(SqList *a)
{
    int DATA,i;
    for(i=0;i<MAXSIZE;++i)
    {
        scanf("%d",&DATA);
        if(DATA == -1){
            break;
        }
        (*a).data[i]=DATA;
    }
    (*a).length=i;
}
