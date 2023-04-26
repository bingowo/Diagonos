#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct x
{
	int a;
	int b;
}; 
int f(int t,int r)
{
	if (t==0&&r!=0) return -2;   
	if (t==0&&r==0) return -1;           
    if (r%t!=0||r/t<0) return -2;  
    return r/t;     
}
int main()
{
	char q[100001];
	scanf("%s",q);
	int len=strlen(q);
	struct x p[100];
	p[0].a=0;p[0].b=0;
	int t,a,b,flag;
	for(int i=0;q[i]!='\0';i++)
	{
		if(q[i]=='U') {p[i+1].a=p[i].a;p[i+1].b=p[i].b+1;}
		if(q[i]=='D') {p[i+1].a=p[i].a;p[i+1].b=p[i].b-1;}
		if(q[i]=='L') {p[i+1].a=p[i].a-1;p[i+1].b=p[i].b;}
		if(q[i]=='R') {p[i+1].a=p[i].a+1;p[i+1].b=p[i].b;}
	}
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		flag=0;
		scanf("%d%d",&a,&b);
		for(int j=0;j<=len;j++)
		{
			int m1=f(-p[len].a,p[j].a-a);
			int m2=f(-p[len].b,p[j].b-b);
			if (m1 == -2||m2 == -2) continue;     
			if (m1 == -1||m2 == -1||m1 == m2)    {flag=1;break;}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
}