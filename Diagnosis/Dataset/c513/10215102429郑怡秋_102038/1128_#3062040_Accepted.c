#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char addr[4000];
}AS;
int cmp1(const void *x,const void *y)
{
    AS *p1=(AS*)x;AS *p2=(AS*)y;
    return strcmp(p1->addr,p2->addr);
}

int main()
{
    int n;
    scanf("%d",&n);
    AS* A=(AS*)malloc(sizeof(AS)*(n+1));
    int k=0;
    for(int i=0;i<n;i++)
    {
        char temp[4000];
        scanf("%s",temp);
        if(temp[4]!='s') strcpy(A[k++].addr,temp);
    }
    qsort(A,k,sizeof(A[0]),cmp1);
    for(int i=0;i<k;i++)
    {
        printf("%s\n",A[i].addr);
    }
    return 0;
}
