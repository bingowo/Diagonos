#include <stdio.h>
#include <stdlib.h>

int s1[1001]={-1},m;

int cmp(void const*a,void const*b)
{
    int* ap=(int*)a;
    int* bp=(int*)b;
    int i,k1=0,k2=0;
    for(i=0;i<m;i++)
    {
        if(*ap==s1[i])
            k1=(i+1);
        if(*bp==s1[i])
            k2=(i+1);
    }
    if(k1!=0&&k2!=0)
        return (k1-k2);
    if(k1==0&&k2!=0)
        return 1;
    if(k1!=0&&k2==0)
        return -1;
    if(k1==0&&k2==0)
        return (*ap-*bp);
    return -1;
}

int main()
{
    int n,i;
    int s2[1001]={-1};
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf("%d",&s1[i]);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&s2[i]);
    qsort(s2,n,sizeof(int),cmp);
    for(i=0;i<n;i++)
        printf("%d ",s2[i]);
}