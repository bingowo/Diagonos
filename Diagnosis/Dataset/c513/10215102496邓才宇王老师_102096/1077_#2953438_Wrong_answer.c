#include <stdio.h>
#include <stdlib.h>
 int A[600];
    int A1[600];
    int B[600];
    int B1[600];
    int B2[600];
        int cmp(const void *p1,const void *p2)
    {
        int *a=p1;
        int *b=p2;
        return A1[*a]-A1[*b];
    }
    int cmp1(const void *p1,const void *p2)
    {
        int *a=p1;
        int *b=p2;
        return *a-*b;
    }
int main()
{

    int m,n;
    scanf("%d",&m);
    for(int j=0;j<m;j++)
        scanf("%d",&A[j]);
    scanf("%d",&n);
    for(int k=0;k<n;k++)
        scanf("%d",&B[k]);
    for(int q=0;q<m;q++)
        A1[A[q]]=q;
    int e=0;
    int t=0;
    for(int w=0;w<n;w++)
    {
        int flag=0;
        for(int r=0;r<m;r++)
        {
            if(B[w]==A[r]) flag=1;
        }
        if(flag==1) B1[e++]=B[w];
        else B2[t++]=B[w];
    }


    qsort(B1,e,4,cmp);
    for(int a=0;a<e;a++)
        printf("%d ",B1[a]);
    qsort(B2,t,4,cmp1);
    for(int b=0;b<t;b++)
        printf("%d ",B2[b]);
}
