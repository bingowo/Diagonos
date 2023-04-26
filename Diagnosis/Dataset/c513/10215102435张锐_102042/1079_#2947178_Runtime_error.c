#include <stdio.h>
#include <stdlib.h>
void f(int *s,int n)
{
    int all=n*(n+1)/2;int i=n;
    for(int j=2;j<=n;j++)
    {
        for(int k=0;k<n;k++)
        {
            s[i]=0;
            while(j)
            {
                s[i]+=s[k+j-1];j--;
            }
            i++;
        }
    }
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
        f(s,n);//重构s
        printf("case #%d:\n",i);
        for(int j=0;j<m;j++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int num=0;
            for(int k=l-1;k<r;k++) num+=s[k];
            printf("%d\n",num);
        }
    }
    return 0;
}
