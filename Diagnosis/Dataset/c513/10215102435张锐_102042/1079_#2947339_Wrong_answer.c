#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int s1=*(int *)a,s2=*(int *)b;
    if(s1>s2) return 1;
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int all=n*(n+1)/2;
        int s[all];
        for(int j=0;j<n;j++) scanf("%d",&s[j]);
        int ii=n;
        for(int j=2;j<=n;j++)
        {
            for(int k=0;k<n;k++)
            {
                s[ii]=0;int jj=j;
                while(jj)
                {
                    s[ii]+=s[k+jj-1];jj--;
                }
                ii++;
                if(ii==all) break;
            }
            if(ii==all) break;
        }
        qsort(s,all,sizeof(int),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<m;j++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            long long int num=0;
            for(int k=l-1;k<=r;k++) num+=s[k];
            printf("%lld\n",num);
        }
    }
    return 0;
}
