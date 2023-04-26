#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long ABS(long long x)
{   long long t;
	if(x<0) t=-x;
	else t=x;
	return t;
}
 void trace(long long x,long long y,int r)// 逆向找路 
 {  if(r)//未走回原点 
 	{   long long d=1LL<<r;//走的距离 
 		 if(ABS(x)>ABS(y)) //保证走后的位置满足(1<<r-1)>=|x|+|y|+1>(1<<r-2) 
		  {  if(x>0) 
		  		{  trace(x-d,y,r-1);
		  			putchar('E');
				  }
 		      else if(x<0)//x==0，0一定小于等于|y| 
			   {  trace(x+d,y,r-1);
			   	   putchar('W');
				 }  	
		  }
		  else 
		  { if(y>0)
		  		{  trace(x,y-d,r-1);
		  			putchar('N');
				  }
		  	else if(y<0)
		  		{ trace(x,y+d,r-1);
		  			putchar('S');
				  }
		  }
	 }
 	putchar('\0');//原点到原点 
 }
int main()
{    long long x,y;
	scanf("%lld %lld",&x,&y);
	int i;
	if(x==0&&y==0) printf("0");
	else if(ABS(x)%2!=ABS(y)%2)//奇数曼哈顿距离才有解 
	{
	for(i=1;;i++) if(ABS(x)+ABS(y)+1<=(1LL<<i)&&ABS(x)+ABS(y)+1>(1LL<<i-1)) break;
	printf("%d\n",i);
	trace(x,y,i);
    }
    else printf("-1");
	return 0;
}