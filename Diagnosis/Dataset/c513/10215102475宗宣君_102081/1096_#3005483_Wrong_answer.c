#include <stdio.h>
#include <stdlib.h>
typedef struct{
int a;
int b;
}record;
int cmp(const void *A,const void *B)
{
    return (*(record*)A).a - (*(record*)B).a;
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int n;
        record A[100];
        scanf("%d",&n);
        for(j = 0;j<n;j++)
            scanf("%d %d",&A[j].a,&A[j].b);
        int flag = 0;
        qsort(A,n,sizeof(record),cmp);
        for(j = 1;j<n;j++)
        {
            if(A[j].a==A[j-1].a) flag = 1;
        }
        if(flag == 0)
        {for(j = 0;j<n;j++)
        {
            for(k = 0;k<n;k++)
            {if(A[j].a==A[k].b) {flag = 1;break;}}
            if(flag==1) break;
        }}
        if(flag==0) printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}
