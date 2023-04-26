#include <stdio.h>
#include <stdlib.h>
typedef struct MyInt
{
    int num;
    int index;
}myint;

int isInA(int A[],int b,int m)
{
    for(int i = 0;i<m;i++)
    {
        if(b == A[i]){return i;}
    }
    return -1;
}
int cmp1(const void *a, const void *b)
{
    myint A = *(myint*)a, B = *(myint*)b;
    return A.index>B.index;
}
int cmp2(const void *a, const void *b)
{
    return *(int*)a>*(int*)b;
}
int main()
{
    int m = 0,n = 0;
    scanf("%d",&m);
    int A[m];memset(A,0,m*sizeof(int));
    for(int i = 0;i<m;i++){scanf("%d",&A[i]);}
    scanf("%d",&n);
    int B[n];memset(B,0,n*sizeof(int));
    for(int i = 0;i<n;i++){scanf("%d",&B[i]);}
    myint BinA[n];memset(BinA,0,n*sizeof(myint));int inCnt = 0;
    int BnotA[n];memset(BnotA,0,n*sizeof(int));int notCnt = 0;
    for(int i = 0;i<n;i++)
    {
        int tmp = isInA(A,B[i],m);
        if(tmp>=0){BinA[inCnt].num = B[i];BinA[inCnt].index = tmp;inCnt++;}
        else{BnotA[notCnt] = B[i];notCnt++;}
    }
    //printf("BinA:\n");
    //for(int i = 0;i<inCnt;i++)
    //{
    //    printf("num = %d, index = %d\n",BinA[i].num,BinA[i].index);
    //    if(i == inCnt-1){printf("\n");}
    //}
    //printf("BnotA:\n");
    //for(int i = 0;i<notCnt;i++)
    //{
    //    printf("num = %d\n",BnotA[i]);
    //    if(i == notCnt-1){printf("\n");}
    //}
    qsort(BinA,inCnt,sizeof(BinA[0]),cmp1);
    qsort(BnotA,notCnt,sizeof(BnotA[0]),cmp2);
    int tmp1 = 0;
    for(int i = inCnt;i<n;i++)
    {
        BinA[i].num = BnotA[tmp1];
        tmp1++;
    }
    for(int i = 0;i<n;i++)
    {
        printf("%d ",BinA[i].num);
    }
    return 0;
}
