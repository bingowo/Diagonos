#include <stdio.h>
#include <stdlib.h>
int max(int a)
{
    if(a<0) a=-a;
    while(a)
    {
        if(a/10) {a=a/10;}
        else return a;
    }
    return a;
}
int cmp(const void*a,const void*b)
{
    int ia=*(int *)a,ib=*(int *)b;
    int ia1=max(ia),ib1=max(ib);
    if(ia1>ib1) return -1;
    if(ia1<ib1) return 1;
    if(ia1=ib1)
    {
        if(ia>ib) return 1;
        if(ia<=ib) return -1;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int num;
        scanf("%d",&num);
        int* A=(int*) malloc(num*sizeof(int));
        for(int j=0;j<num;j++)
        {
            scanf("%d",&A[j]);
        }
        qsort(A,num,sizeof(int),cmp);
        for(int k=0;k<num;k++)
        {
            if(k<num-1) printf("%d ",A[k]);
            else printf("%d\n",A[k]);
        }
        free(A);
    }
    return 0;
}
