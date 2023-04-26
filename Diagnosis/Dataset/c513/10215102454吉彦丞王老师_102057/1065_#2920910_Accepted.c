#include<stdio.h>
int T(int n)
{
    if(n==1)
    {
        return 1;
    }
    else if(n==2)
    {
        return 1;
    }
    else
    {
        return T(n-1)+T(n-2);
    }
}
int add(int n)
{
    int d=0;
    for(int i=1;i<n+1;i++)
    {
        d=d+T(i);
    }
    return d;
}
int D(int a,int y,int n)
{
	if(n==1||n==2)
	{
		return 0;
	}
	else if(n==3)
	{
		return a;
	}
	else if(n==4)
	{
		return y;
	}
	else
	{
		return D(a,y,n-1)+D(a,y,n-2);
	}
}
int F(int a,int y,int n)
{
    if(n==1)
    {
        return a;
    }
    else
    {
        return F(a,y,n-1)+D(a,y,n);
    }
}
int main()
{
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int y;
    if(x==1||x==2)
    {
        printf("%d",a);
    }
    else if(x==3)
    {
        printf("%d",2*a);
    }
    else
    {
        y=(m-2*a-add(n-5)*a)/add(n-4);
        printf("%d",F(a,y,x));
    }
    return 0;
}