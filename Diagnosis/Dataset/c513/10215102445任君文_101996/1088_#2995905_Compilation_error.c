#include<stdio.h>
#include<stdlib.h>
unsigned long long jcs(int m, int n)
{

    if(n==1)
        return m;
    else 
        return (m/n)*jcs(m-1,n-1);
}
int main()
{
    int T;
    int i;
    int m,n,t;
    unsigned long long res=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        fz=0;
        fm=0;
        scanf("%d%d",&m,&n);
        t=m-n;
        if(t<n)
            n=t;
        printf("case #%d:\n",i);
        if(n==0)
            printf("1\n");
        else if(n==1)
            printf("%d\n",m);
        else
        {

            res=jcs(m,n);
            printf("%llu\n",res);
        }
    }
    return 0;
}