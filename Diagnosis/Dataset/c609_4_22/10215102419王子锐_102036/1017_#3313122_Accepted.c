#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpA(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int cmpD(const void *a,const void *b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    char c;
    int a[100],tmp;
    int flag[1001]= {0};
    scanf("%c\n",&c);
    int i=0;
    while(scanf("%d",&tmp)!=EOF)
    {
        if(flag[tmp]==0)
        {
            a[i++]=tmp;
            flag[tmp]=1;
        }
    }
    if(c=='A') qsort(a,i,sizeof(a[0]),cmpA);
    if(c=='D') qsort(a,i,sizeof(a[0]),cmpD);
    for(int j=0; j<i; j++)    printf("%d ",a[j]);
    return 0;
}