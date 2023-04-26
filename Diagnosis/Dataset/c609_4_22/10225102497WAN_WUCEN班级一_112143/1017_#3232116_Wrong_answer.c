#include <stdio.h>
#include <stdlib.h>

int ascmp(const void*a,const void *b)
{   if (*(int*)a==*(int*)b)*(int*)b=0;
    return *(int*)a-*(int*)b;
}

int dscmp(const void*a,const void *b)
{   if (*(int*)a==*(int*)b)*(int*)b=0;
    return *(int*)b-*(int*)a;
}
int main()
{   char alpha=0;
    int n[100]={0},i=0;
    scanf("%c",&alpha);
    while(scanf("%d",&n[i++])!=EOF);
    if(alpha=='A')qsort(n,i-1,4,ascmp);
    else qsort(n,i-1,4,dscmp);
    for(i=0;n[i]==0;i++);
    for(;n[i+1]!=0;i++)
        printf("%d ",n[i]);
    return 0;
}
