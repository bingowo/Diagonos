#include <stdio.h>
#include <stdlib.h>

int cmp1(const void*a,const void*b)
{
    int c=*(int*)a;
    int d=*(int*)b;
    if(c<d)return -1;
    else return 1;
}

int cmp2(const void*a,const void*b)
{
    int c=*(int*)a;
    int d=*(int*)b;
    if(c<d)return 1;
    else return -1;
}


int main()
{
    int n,i,j,sum,cas;
    int t[1001],s[1001];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&cas);
        for(j=0;j<cas;j++)scanf("%d",&t[j]);
        qsort(t,cas,sizeof(t[0]),cmp1);
        for(j=0;j<cas;j++)scanf("%d",&s[j]);
        qsort(s,cas,sizeof(s[0]),cmp2);
        for(j=0,sum=0;j<cas;j++)sum=sum+s[j]*t[j];
        printf("case #%d:\n",i);
        printf("%d\n",sum);
        for(j=0;j<cas;j++){t[j]='\0';s[j]='\0';}
    }
    return 0;
}
