#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int flag;
}ArrB;

int cmp(const void*a,const void*b)
{
    ArrB a1,b1;
    a1=*(ArrB*)a;
    b1=*(ArrB*)b;
    if(a1.flag==-1&&b1.flag==-1)
    {
        if(a1.num<b1.num) return -1;
        else return 1;
    }
    else if(a1.flag==-1&&b1.flag!=-1) return 1;
    else if(a1.flag!=-1&&b1.flag==-1) return -1;
    else return a1.flag-b1.flag;
}

int main()
{
    int m,n,A[501];
    ArrB B[501];
    for(int i=0;i<501;++i) B[i].flag=-1;
    scanf("%d",&m);
    for(int i=0;i<m;++i) scanf("%d",&A[i]);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&B[i].num);
        for(int j=0;j<m;++j)
        {
            if(A[j]==B[i].num)
            {
                B[i].flag=j;
                break;
            }
        }
    }
    qsort(B,n,sizeof(ArrB),cmp);
    for(int i=0;i<n;++i)
    {
        printf("%d ",B[i].num);
    }
    printf("\n");
    return 0;
}
