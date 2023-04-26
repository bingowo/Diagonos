#include<stdio.h>
int u[20],v[20],su[20],sv[20];
int main()
{
    int a,n,m,x,i,t,ans;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    for(i=1;i<n;i++)
    {
        if(i==1)
        {
            u[i]=1;
            v[i]=0;
            su[i]=1;
            sv[i]=0;
        }
        else if(i==2)
        {
            u[i]=0;
            v[i]=1;
            su[i]=1;
            sv[i]=0;
        }
        else
        {
            u[i]=u[i-1]+u[i-2];
            v[i]=v[i-1]+v[i-2];
            su[i]=su[i-1]+u[i-2];
            sv[i]=sv[i-1]+v[i-2];
        }
    }
    t=(m-su[n-1]*a)/sv[n-1];
    ans=su[x]*a+sv[x]*t;
    printf("%d",ans);
    return 0;
}