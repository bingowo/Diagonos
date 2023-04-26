#include<stdio.h>

int f(int index)
{
    int b=1,d=1,t;
    if(index==1 || index==3|| index==4)
        return 1;
    else if(index==2)
        return 0;
    else
    {
        for(int i=0;i<index-4;i++)//a在第index(大于等于6)站的系数，循环index-5次
    	{
        	t=b+d;
        	b=d;
        	d=t;
    	}
    	return t;
    }
}


int g(int index)
{
    int b=1,d=1,t;
    if(index==1)
        return 0;
    else if(index==2 || index==3)
        return 1;
    else
    {
        for(int i=0;i<index-3;i++)//t在第index(大于等于5)站的系数，循环index-4次
    	{
        	t=b+d;
        	b=d;
        	d=t;
    	}
    	return t;
    }
}


int main()
{
    int a,n,m,x,sum,t;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    t = (m-a*(1+f(n-2)+f(n-3)))/(g(n-2)+g(n-3)-1);
    if(x==1 || x==2)
        sum = a;
    else
        sum=a*(f(x-2)+f(x-1)+1)+t*(g(x-2)+g(x-1)-1);
    printf("%d",sum);
    return 0;
}

