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
    int s[1000];int i = 0,j;
    while(scanf("%d",&s[i])!=EOF) i++;
    qsort(s,i,sizeof(s[0]),cmp);
    for(j = 0;j<i;j++)
        printf("%d ",s[j]);
    return 0;
}
