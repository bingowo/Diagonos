#include<stdio.h>

int f(int index)
{
    int b=1,d=1,t;
    if(index==1 || index==4 || index==5)
        return 1;
    else if(index==2 || index == 3)
        return 0;
    else
    {
        for(int i=0;i<index-5;i++)//a在第index(大于等于6)站的系数，循环index-5次
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
    else if(index==2 || index==3 || index==4)
        return 1;
    else
    {
        for(int i=0;i<index-4;i++)//t在第index(大于等于5)站的系数，循环index-4次
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
    t = (m-a*(f(n-2)+1-f(n-4)))/(g(n-2)-g(n-4)-1);
    printf("%d\n",t);
    
    
    //对车站数分类,n至少为2，
    sum=a*(f(x-2)+f(x-1)+1)+t*(g(x-2)+g(x-1)-1);
    printf("%d",sum);
    return 0;
}

