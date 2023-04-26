#include<stdio.h>
#include<math.h>
#include<string.h>
void f(int a,int b)
{
	int x,y;
	//TODO 结束条件 
	if(((a!=0)||(b!=0))&&((abs(a)%2==0&&abs(b)%2==0)||(abs(a)%2!=0&&abs(b)%2!=0)))
	{
		x=(b-a)/2;y=(-a-b)/2;
		f(x,y);
		printf("0");
	}
	else 
	{
		if(a==0&&b==0) {return;}   
		else 
		{
			if(abs(a)<abs(b))
			{f(a,b-1);printf("1");}
			else{f(a-1,b);printf("1");}
			
		}
		}
}
int main()
{
	int a,b=0;char c;
	scanf("%d",&a);
	char s=getchar();
	if(s=='+'||s=='-') 
	{
		scanf("%c",&c);
		if(c>'0'||c<'9')
		{
			if(s=='+') b=c-48;
			else b=-(c-48);
		}
		if(c=='i')
		{
			if(s=='+') b=1;
			else b=-1;
		}
	}
	f(a,b);
	
	
	
	
	return 0;
	
	
 } 