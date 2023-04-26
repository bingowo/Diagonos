#include<stdio.h>
#include<math.h>
#include<string.h>
void f(int a,int b)
{
	int x,y;
	//TODO 循环余数 
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
			a=a-1;
			x=(b-a)/2;y=(-a-b)/2;
			f(x,y);
			printf("1");
			
		}
		}
}
int main()
{
	int a,b=0;char c[18];
	scanf("%d",&a);
	char s=getchar();
	if(s=='+'||s=='-') 
	{
		scanf("%s",c);
		int i=0;
		if(c[0]=='i') b=1;
		while(c[i]!='i')
		{
			b=(b+(c[i]-48))*10;i++;
		}
		if(s=='-')  b=-b;
		
	}
	f(a,b);
	
	
	
	
	return 0;
	
	
 } 