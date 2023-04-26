#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	char q[100001];
	scanf("%s",q);
	int x=0,y=0,t;
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
		int a,b;
		scanf("%d %d",&a,&b);
		if(a<x&&b<y) {printf("NO\n");continue;}
		while(a>=x&&b>=y)
		{
			a=a-x;b=b-y;
		}
		int j=0;
		while((a!=0&&b!=0)&&(q[j]=='\0'))
		{
			if(q[j]=='U') {b-=1;}
			if(q[j]=='D') {b+=1;}
			if(q[j]=='L') {a+=1;}
			if(q[j]=='R') {a-=1;}
			j++;			
		}
		if(a==0&&b==0) printf("YES\n");
		else printf("NO\n");
	}
}