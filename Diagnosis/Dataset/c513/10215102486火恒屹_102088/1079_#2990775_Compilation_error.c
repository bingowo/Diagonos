#include <stdio.h>
#include <stdlib.h>

#define N 1002
int num[N]={0};
int res[N*(N+1)/2]={0};
int n;
int k=1;

int cmp(const void*a,const void*b)
{
    int x=(*int)*a;
    int y=(*int)*b;
    return x-y;
}
void jump(int p)
{
    res[k]=res[k]+num[p];
    k++;
    if(p==n) return;
    else
    {
        for(int z=p+1;z<=n;z++)
            jump(z);
    }
        
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int m;
        scanf("%d %d",&n,&m);
        for(int j=1;j<=n;j++)
            scanf("%d",&num[j]);
        for(int j=1;j<=n;j++)
            jump[j];
        qsort(res,n*(n+1)/2+1,sizeof(int),cmp);
        for(int j=0;j<m;j++)
        {
            int start,end;
            int sum=0;
            scanf("%d %d",&start,&end);
            for(int x=start,x<=end,x++)
                sum=sum+res[x];
            printf("%d\n",sum);
        }
    }
    return 0;
}
