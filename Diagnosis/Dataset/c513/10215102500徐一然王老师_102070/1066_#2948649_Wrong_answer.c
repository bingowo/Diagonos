#include <stdio.h>

long long int F(int n,int p,int m,int t)
{   long long int A[200];long long int B[200];
    int flag=0;
    for(int j=0;j<200;j++)
    {
        A[j]=0;B[j]=0;
    }
    m--;
    if(p==n)
    A[p+1]=1;
    if(p==1)
    A[p-1]=1;
    if(p!=n&&p!=1)
    {
        A[p+1]=1;A[p-1]=1;
    }
    while(m)
    {
        if(flag==0)
        {
                for(int i=1;i<n+1;i++)
            {
                B[i]=A[i-1]+A[i+1];
                flag=1;
            }
        }
        else if(flag==1)
        {
            for(int i=1;i<n+1;i++)
            {
                A[i]=B[i-1]+B[i+1];
                flag=0;
            }
        }
        m--;
    }
    if(flag==1)
    {
        return B[t];
    }
    else
    {
        return A[t];
    }

}

int main()
{
    int cas;
    int n,p,m,t;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d %d %d %d",&n,&p,&m,&t);
        printf("%lld\n",F(n,p,m,t));
    }
}
