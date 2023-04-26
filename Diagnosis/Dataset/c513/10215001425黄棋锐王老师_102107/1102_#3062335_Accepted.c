#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000000007

typedef struct
{	
	long long int x;
	long long int y;
}point;

//正整数的平方都在函数的右上角和左下角
//偶数平方左下角，奇数平方右上角 
// 相邻平方数a^2和b^2(a<b) dx=a,dy=b

int main() 
{ 	long long int a=0,b=0;
	scanf("%lld",&a);
	while((b+1)*(b+1)<=a) b++;//b^2<=a<(b+1)^2,找分界点b,b+1
	point p={0,0};
	long long int c=a-b*b;//a与分界点的数值差 
	
	if(b%2==0)//b^2在左下角,b为偶数 
	{	p.x=(-1)*b/2;//该分界点b^2的位置 
		p.y=(-1)*b/2;
		
		if(c>b)//所求点的位置 
		{ p.x+=b;
		p.y+=c-b;
		}
		else
			p.x+=c;		
	}
	
	else//b^2在右上角,b为奇数
	{	p.x=b/2;
		p.y=p.x+1;
		
			
		if(c>b)//所求点的位置 
		{ p.x-=b;
		p.y-=c-b;
		}
		else
			p.x-=c;		
	}
	
	printf("(%lld,%lld)\n",p.x,p.y);
	
	return 0;
}