#include<stdio.h>
#include<math.h>

int cmp1(const void*a,const void*b)
{
    int c=*(int*)a;
    int d=*(int*)b;
    return c-d;
}

int cmp2(const void*a,const void*b)
{
    int c=*(int*)a;
    int d=*(int*)b;
    return d-c;
}

int main()
{
    char c;
    int ans[1005],p[1005],i=0,j=0,k=0,x=0;
    scanf("%c",&c);
    while(scanf("%d",&p[i])!=EOF)
           i++;
    ans[0]=p[0];
    int x[1005];
    for(k=0;k<1005;k++) x[k]=-1;
    for(j=0,k=0;j<i;j++)
    {
    if(x[p[j]]==-1)
    {
        anx[k++]=p[j];
        x[p[j]]=0;
    }
    }
    switch(c)
    {
        case 'A':qsort(ans,k,sizeof(int),cmp1);break;
        case 'D':qsort(ans,k,sizeof(int),cmp2);break;
    }
    for(i=0;i<k;i++)
        printf("%d%c",ans[i],i==k-1?'\n':' ');//别忘记%c
    return 0;
}