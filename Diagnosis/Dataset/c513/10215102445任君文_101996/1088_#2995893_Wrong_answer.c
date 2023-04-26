#include<stdio.h>
#include<stdlib.h>
long jc(int n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else 
        return n*jc(n-1);
}
long jcs(int m, int n)
{

    if(n==1)
        return m;
    else 
        return m*jcs(m-1,n-1);
}
int main()
{
    int T;
    int i;
    int m,n,t;
    long res=0;
    long fm=0,fz=0;
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
            printf("%ld\n",m);
        else
        {
            fm=jc(n);
            fz=jcs(m,n);
            res=fz/fm;
            printf("%ld\n",res);
        }
    }
    return 0;
}