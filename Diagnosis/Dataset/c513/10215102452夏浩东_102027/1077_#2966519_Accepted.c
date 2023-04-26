#include <stdio.h>
#include <stdlib.h>
int A[500];
int num1=0,num2=0;
int cmp(const void *a,const void *b)
{
    int *m = (int*)a;
    int *n = (int*)b;
    int res1=-1,res2=-1;
    for(int i=0;i<num1;i++)
    {
        if(A[i]==*m) res1=i;
        if(A[i]==*n) res2=i;
    }
    if(res1==-1 && res2!=-1) return 1;
    else if(res1 !=-1 && res2==-1) return -1;
    else if(res1==-1 && res2==-1) return (*m-*n);
    else return res1-res2;
}
int main()
{
    int B[500];
    scanf("%d",&num1);
    for(int i=0;i<num1;i++)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d",&num2);
    for(int i=0;i<num2;i++)
    {
        scanf("%d",&B[i]);
    }
    qsort(B,num2,sizeof(int),cmp);
    for(int i=0;i<num2;i++) printf("%d ",B[i]);
    return 0;
}