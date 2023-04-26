#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void f(int w[],int e,int a[])
{
	if(w[e]==10) 
	{
		w[e]=16-w[e]-w[e+1]-w[e+2]-w[e+3];a[w[e]]++;
	}
	else if(w[e+1]==10) 
	{
		w[e+1]=16-w[e]-w[e+1]-w[e+2]-w[e+3];a[w[e+1]]++;		
	}
	else if(w[e+2]==10) 
	{
		w[e+2]=16-w[e]-w[e+1]-w[e+2]-w[e+3];a[w[e+2]]++;	
	}
	else if(w[e+3]==10)
	{
		w[e+3]=16-w[e]-w[e+1]-w[e+2]-w[e+3];a[w[e+3]]++;	
	}
	for(int j=e-1;j>=0;j--)
	{
		if(w[j]==10){w[j]=w[j+4];a[w[j+4]]++;}
	}
	for(int j=e+4;w[j]!=-1;j++)
	{
		if(w[j]==10){w[j]=w[j-4];a[w[j-4]]++;}
	}
}
int main()
{
	int t,a[4],e,w[101];
	char s[101]; 
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		a[1]=0;a[2]=0;a[3]=0;a[0]=0;e=0;
		scanf("%s",s);
		int j=0;
		for(;s[j]!='\0';j++)
		{
			if(s[j]=='R') w[j]=1;
			else if(s[j]=='B') w[j]=2;
			else if(s[j]=='Y') w[j]=3;
			else if(s[j]=='G') w[j]=0;
			else w[j]=10;
		}
		w[j]=-1;
		for(j=0;w[j+3]!=-1;j++)
		{
			if(w[j]+w[j+1]+w[j+2]+w[j+3]<=16) {e=j;break;}
		}
		f(w,e,a);
		printf("case #%d:\n%d %d %d %d\n",i,a[1],a[2],a[3],a[0]);
	}

	
}