#include <stdio.h>
#include <stdlib.h>
int cmp1(const void *a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int cmp2(const void *a,const void*b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    char a,b;
    int n;
    int m[1000];
    int j=0;
    int flag[1000]={0};
    scanf("%c",&a);
    while(scanf("%d",&n)!=EOF)
    {
        if(flag[n]==0)
        {
            m[j++]=n;
            flag[n]=1;
        }
    }
    if(a=='A') qsort(m,j,sizeof(m[0]),cmp1);
    if(a=='D') qsort(m,j,sizeof(m[0]),cmp2);
    for(int k=0;k<j-1;k++)
        printf("%d ",m[k]);
    printf("%d",m[j-1]);
    return 0;
}