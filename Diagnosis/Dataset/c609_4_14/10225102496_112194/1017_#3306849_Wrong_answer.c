#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp1(const void *a,const void *b){return *(int*)b-*(int*)a;}
int cmp2(const void *a,const void *b){return *(int*)a-*(int*)b;}
int main()
{
    char c;
    int a[100],l,tmp;
    int flag[1001]={0};
    scanf("%c\n",&c);
    int i=0,j,k;
    while(scanf("%d",&tmp)!=EOF)
    {
        if(flag[tmp]==0)
        {
            a[i++]=tmp;
            flag[tmp]=1;
        }
    }
    if(c=='A') qsort(a,i,sizeof(a[0]),cmp2);
    if(c=='D') qsort(a,i,sizeof(a[0]),cmp1);
    for(j=0;j<i-1;j++)    
    {printf("%d ",a[j]);}
    return 0;
}