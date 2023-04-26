#include<stdio.h>
#include<stdlib.h>
int jc(int n)
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
int jcs(int m, int n)
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
    int res=0;
    int fm=0,fz=0;
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
            fm=jc(n);
            fz=jcs(m,n);
            res=fz/fm;
            printf("%d\n",res);
        }
    }
    return 0;
}