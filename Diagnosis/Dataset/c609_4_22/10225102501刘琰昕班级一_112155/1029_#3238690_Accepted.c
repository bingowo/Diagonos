#include <stdio.h>
#include <stdlib.h>

int A[1001]={0};

int cmp(const void *num1_,const void *num2_)
{
    int num1=*(int *)num1_;
    int num2=*(int *)num2_;
    if(A[num1]==A[num2])
        return num1>num2?1:-1;
    else
        return A[num1]>A[num2]?-1:1;
}

int main()
{
    int m,digit;
    scanf("%d",&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d",&digit);
        A[digit]=m-i;
    }
    int n,*B;
    scanf("%d",&n);
    B=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&B[i]);
    qsort(B,n,sizeof(int),cmp);
    for(int i=0;i<n;i++)
        printf("%d ",B[i]);
    free(B);
    return 0;
}
