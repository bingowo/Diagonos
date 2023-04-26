#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000

typedef struct
{
	int c0,c1,c2;
}FUN;


int GCD(int x,int y)
{
	int r;
	r=x%y;
	if(r==0) return y;
	else GCD(y,r);
}

int fun(FUN fx,int x)
{
	int y=0;
	y=fx.c0+fx.c1*x+fx.c2*x*x;
	return y;
}

int main() 
{ 	char s[100]={'\0'};
	scanf("%s",s);
	
	FUN fx={0,0,0};
	int i=0,l=strlen(s),j=0;
	do
 { 	char xi[100]={'\0'};
 	int sign=1;//记录符号
 	
 	if(s[i]=='+') sign=1,i++;
 	else if(s[i]=='-') sign=-1,i++;//处理符号，可有可无，'+','-',或无符号 
 	
 	
 	for(j=0;i<l&&'0'<=s[i]&&s[i]<='9';i++) xi[j++]=s[i];//记录数值 
	int val=1;
	if(strlen(xi)>0) val=atoi(xi);
	
 	if(s[i]=='x')
	 {	
	 	if(i+1<l&&s[i+1]=='^')
	 	{	i=i+2;
	 		if(s[i]=='2') fx.c2=val*sign;
		 }
		 
	 	else fx.c1=val*sign;
	 	i++;//key
	 }
	 
 	else fx.c0=val*sign;//常数项 
	  
 }while(i<l);
    //*********************读入f(x) 
	
	int a=fx.c2,b=fx.c1,c=fx.c0;
	double d=b*b-4*a*c;
	if(d<0) printf("No Answer!");
	else
	{	d=sqrt(d);
		int di=(int)d;
		int z1=0,z2=0,m1=2*a,m2=2*a,p1=1,p2=1,r;//p为x的系数 
		z1=-b+di;
		z2=-b-di;
		r=GCD(z1,m1);
		z1/=r,m1/=r;
		r=GCD(z2,m2);
		z2/=r,m2/=r;
		
		
	if(a!=1)
	{	if(m1<0) z1*=-1,m1*=-1;
		p1=m1;
		a/=m1;
		
		if(a!=1)
		{	if(m2<0) z2*=-1,m2*=-1;
			p2=m2;
		}
	}
	
	z1*=-1,z2*=-1;
	int h,l;
	if(p1>p2)
	{
		int t=p1;
		p1=p2,p2=t;
		t=z1,z1=z2,z2=t;
	}
	
	printf("%d %d %d %d",p1,z1,p2,z2);
		
	}


    return 0;
}