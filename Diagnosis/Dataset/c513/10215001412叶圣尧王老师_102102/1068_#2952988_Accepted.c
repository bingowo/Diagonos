#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int n,m;scanf("%d %d",&n,&m);
    while(n!=-1&&m!=-1)
    {
        int p[n+1];p[0]=1;
        for(int i=1;i<=n;i++)
        {
            if(i<m)p[i]=p[i-1]*2;
            else if(i==m)p[i]=p[i-1]*2-1;
            else
                p[i]=p[i-1]*2-p[i-m-1];
        }
        int d=pow(2,n)-p[n];
        printf("%d\n",d);
        scanf("%d%d",&n,&m);
    }
}
