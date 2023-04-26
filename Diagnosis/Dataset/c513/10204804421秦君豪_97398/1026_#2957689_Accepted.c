#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmp(const void* a,const void *b)
{
    int a1=*(int*)a;
    int b1=*(int*)b;
    return a1>b1?1:-1;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    int *x=(int*)malloc(sizeof(int)*n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    qsort(x,n,sizeof(x[0]),cmp);
    int m=n/2;
    int ret=0;
    for(int i=0;i<n;i+=2)
    {
//        printf("i=%d,j=%d\n",i,j);
//        printf("pass");
        ret+=abs(x[i]-x[i+1]);
    }
    printf("%d",ret);
    free(x);
}
