#include <stdio.h>
#include <stdlib.h>
int cmp1(const void *a,const void *b)
{
    return *((int *)a) - *((int *)b);
}
int cmp2(const void *a,const void*b)
{
    return *((int*)b) - *((int *)a);
}
int main()
{
    char a;
    scanf("%c",&a);
    int s[100];
    int i;
    for(i = 0;scanf("%d",&s[i]) !=EOF;i++);
    if(a =='A')qsort(s,i,sizeof(s[0]),cmp1);
    else qsort(s,i,sizeof(s[0]),cmp2);
    s[i+1] = 0;
    int j,k;
    for( j = 0;j<i;j++)
    {
        if(s[j] ==s[j+1]) j++;
        if(s[j] !=s[j+1])printf("%d ",s[j]);
    }
    return 0;
}