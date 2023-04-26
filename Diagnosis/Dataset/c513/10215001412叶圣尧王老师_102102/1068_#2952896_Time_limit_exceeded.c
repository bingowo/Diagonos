#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,m;scanf("%d %d",&n,&m);
    while(n!=0&&m!=0)
    {
        int p[n+1];p[0]=1;
        for(int i=1;i<=n;i++)
        {
            if(i<m)p[i]=p[i-1]*2;
            else if(i==m)p[i]=p[i-1]*2-1;
            else 
                p[i]=p[i-1]*2-p[i-m-1];
        }
        printf("%d\n",pow(2,n)-p[n]);
        scanf("%d%d",&n,&m);
    }
}