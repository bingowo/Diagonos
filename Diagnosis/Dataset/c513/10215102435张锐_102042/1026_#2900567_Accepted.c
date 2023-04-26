#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    int s1=*(int *)a,s2=*(int *)b;
    return s1-s2;
}
int main()
{
    int n;
    scanf("%d",&n);
    int *A=(int *) malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    qsort(A,n,sizeof(int),cmp);
    int num=0;
    for(int i=1;i<n;i=i+2)
    {
        num+=A[i]-A[i-1];
    }
    printf("%d",num);
    return 0;
}
