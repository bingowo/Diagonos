#include <stdio.h>
#include <stdlib.h>
int Num(int x)
{
    int n  = 0;
    for(;x!=0;n++)
        x = x/10;
    return n;
}
int cmp(const void *a,const void *b)
{
    int x = *((int*)a);
    int y = *((int*)b);
    int m = Num(x),n = Num(y);
    if(m>n) return -1;
    else if(m<n)return 1;
    else if(m ==n) return x-y;
}
int main()
{
    int *s = NULL;int i = 0,j;
    s = (int *)malloc(sizeof(int)*1000000);
    while(scanf("%d",&s[i])!=EOF) i++;
    qsort(s,i,sizeof(s[0]),cmp);
    for(j = 0;j<i;j++)
        printf("%d ",s[j]);
        free(s);
        s = NULL;
    return 0;
}
