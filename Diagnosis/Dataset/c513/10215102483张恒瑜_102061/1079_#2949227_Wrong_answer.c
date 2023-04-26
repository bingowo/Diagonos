#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {   
        int m,n;
        scanf("%d%d",&n,&m);
        int in[n],sort[n*(n+1)/2],cnt=0;
        for(int i=0;i<n;i++) scanf("%d",&in[i]);
        if(n==1) sort[0]=in[0];
        for(int len=1;len<n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                int tmp=0;
                for(int j=i;j<i+len;j++)
                {
                    tmp+=in[j];
                }
                sort[cnt++]=tmp;
            }
        }
        qsort(sort,cnt,sizeof(sort[0]),cmp);

        printf("case #%d:\n",t);
        for(int i=0;i<m;i++)
        {
            int L,J,res=0;
            scanf("%d%d",&L,&J);
            for(int j=L-1;j<J;j++)
                res+=sort[j];
            printf("%d\n",res);
        }
    }
    return 0;
}