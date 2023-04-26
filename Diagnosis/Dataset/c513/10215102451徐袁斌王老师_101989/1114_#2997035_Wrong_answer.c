#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int GCD(int a,int b)
{
	int r;
	while(b>0)
	{
		r=a%b;a=b;b=r;
	}
	return a;
}
int main()
{
	int d=1,ans=0,c[4]={0};
    char s[100];
    scanf("%s",s);
    for(int i=0;s[i-1]!='\0';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			while(s[i]>='0'&&s[i]<='9'&&s[i]!='\0')
			{
				ans=ans*10+s[i]-'0';
				i++;
			}
			if(s[i]=='\0') c[0]=ans*d;
			else i--;
		}
		else if(s[i]=='x')
		{
			if(s[i-1]<='0'||s[i-1]>='9') ans=1;
			if(s[i+1]=='^')  continue;
			else {c[1]=d*ans;ans=0;d=1;}
		}
		else if(s[i]=='^')
		{
			i++;
			c[s[i]-'0']=d*ans;
			ans=0;d=1;
		}
		else if(s[i]=='+') {d=1;ans=0;}
		else if(s[i]=='-') {d=-1;ans=0;}
		else if(s[i]=='\0')
		{
			c[0]=d*ans;
		}
	}
	int deerta=c[1]*c[1]-4*c[2]*c[0];
	if((int)sqrt(deerta)*(int)sqrt(deerta)!=deerta)
	{
		printf("No Answer!");
	}
    else
    {
		int f1=c[1]+(int)sqrt(deerta),f2=c[1]-(int)sqrt(deerta),m=-2*c[2];
		int k1,k2;
		if(abs(m)>abs(f1)) k1=GCD(abs(m),abs(f1));
		else k1=GCD(abs(f1),abs(m));
		if(m<0) {m=-m;f1=-f1;f2=-f2;}
		int a1=m/k1,c1=f1/k1;
		if(abs(m)>abs(f2)) k2=GCD(abs(m),abs(f2));
		else k2=GCD(abs(f2),abs(m));
		int a2=m/k2,c2=f2/k2;
		if(a1<a2)
		{
			printf("%d %d %d %d",a1,-c1,a2,-c2);
		}
		else if(a1>a2)
		{
			printf("%d %d %d %d",a2,-c2,a1,-c1);
		}
		else if(a1==a2)
		{
			if(-c1<=-c2) printf("%d %d %d %d",a1,-c1,a2,-c2);
			else printf("%d %d %d %d",a1,-c2,a2,-c1);
		}
	}
}