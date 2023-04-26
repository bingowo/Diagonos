#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p1,const void *p2)
{
    int *a=(int*)p1;
    int *b=(int*)p2;
    return *a-*b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int *values=(int*)malloc(sizeof(int)*(n+2));
    int i=0;
    for(;i<n;i++)
        scanf("%d",values+i);
    qsort(values,n,sizeof(int),cmp);
    int answer=0;
    for(i=0;i<n/2;i++)
        answer+=(-*(values+2*i)+*(values+2*i+1));
    printf("%d",answer);
    return 0;
}