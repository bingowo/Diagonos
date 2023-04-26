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
	int a=0,b=0,c=1,i=0,e=1;char d[38];
	scanf("%s",d);
	if(d[i]=='-') {e=-1;i++;}
	while(d[i]!='+'&&d[i]!='-'&&d[i]!='\0')
	{
		if(d[i]=='i') {b=a;a=0;i++;break;}
		a=(a+d[i]-48)*10;i++;
	}
	a=a/10;
	if(a!=0){a=a*e;}
	else{b=b*e;}
	if(d[i]=='-') {c=-1;i++;}
	if(d[i]=='+') {i++;}
	if(d[i]=='i') b=1;
	while(d[i]!='i'&&d[i]!='\0')
	{
		b=(b+(d[i]-48))*10;i++;
	}
	if(abs(b)>=10){b=b/10;}
	b=b*c;
	if(a==0&&b==0) printf("0");

	f(a,b);
	
	
	
	return 0;
	
	
 } 