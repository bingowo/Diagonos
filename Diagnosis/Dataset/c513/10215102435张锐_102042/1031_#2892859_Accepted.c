#include <stdio.h>
#include <stdlib.h>
int cmpA(const void*a,const void*b)
{
    int ia=*(int *)a,ib=*(int *)b;
    if(ia>ib) return -1;
    if(ia<=ib) return 1;
}
int cmpB(const void*a,const void*b)
{
    int ia=*(int *)a,ib=*(int *)b;
    if(ia>ib) return 1;
    if(ia<=ib) return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        int n=0;
        scanf("%d",&n);
        getchar();char c;
        int *A=(int*) malloc(n*sizeof(int));
        int *B=(int*) malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            scanf("%d",&A[j]);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d",&B[j]);
        }
        qsort(A,n,sizeof(int),cmpA);
        qsort(B,n,sizeof(int),cmpB);
        int x=0;
        for(int i=0;i<n;i++)
        {
            x+=A[i]*B[i];
        }
        printf("case #%d:\n",i);
        printf("%d\n",x);
        free(A);free(B);
    }
    return 0;
}
