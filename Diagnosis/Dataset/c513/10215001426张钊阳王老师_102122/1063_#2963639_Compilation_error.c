#include <stdio.h>
#include <stdlib.h>

int main()
{
    void swap(long long int *x,long long int *y);

    long long int x,y,temp;

    scanf("%lld %lld",&x,&y);
    
    long long ans=0;
	while(x!=0&&y!=0)//就是一个数学迭代，像gcd的辗转相除法 
	{
		swap(&x,&y);//交换x,y 
		s=s+4*y*(x/y);//长方形剩下的所有最大正方形 
		x=x%y; 
	}

    printf("%lld",ans);

    return 0;
}

void swap(long long int *x,long long int *y)
{
    long long temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
