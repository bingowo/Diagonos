#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	char q[100001];
	scanf("%s",q);
	int x=0,y=0,t,a,b,c=0,d=0;
	for(int i=0;q[i]!='\0';i++)
	{
		if(q[i]=='U') {y+=1;}
		if(q[i]=='D') {y-=1;}
		if(q[i]=='L') {x-=1;}
		if(q[i]=='R') {x+=1;}
	}
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		c=0;d=0;
		scanf("%d%d",&a,&b);
		if((a>=0&&x>=0)||(a<=0&&x<=0)) c=1;
		if((b>=0&&y>=0)||(b<=0&&y<=0)) d=1;
		if(x==0&&y!=0&&c&&d)
		{
			while(abs(b)>=abs(y)) b=b-y;
		}
		else if(y==0&&x!=0&&c&&d)
		{
			while(abs(a)>=abs(x)) a=a-x;
		}
		while(abs(a)>abs(x)&&abs(b)>abs(y)&&c&&d)
		{
			a=a-x;b=b-y;
		}
		int j=0;
		while((a!=0||b!=0)&&(q[j]!='\0'))
		{
			if(q[j]=='U') {b-=1;}
			else if(q[j]=='D') {b+=1;}
			else if(q[j]=='L') {a+=1;}
			else if(q[j]=='R') {a-=1;}
			j++;			
		}
		if(a==0&&b==0) printf("YES\n");
		else printf("NO\n");
	}
}