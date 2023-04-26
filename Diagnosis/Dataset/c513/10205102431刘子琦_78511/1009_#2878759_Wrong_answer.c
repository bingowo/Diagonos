#include<stdio.h> 
#include<string.h>
int g(int a,int b)
{
	if(b==0)return a;
	return g(b,a%b);
}
int main()
{
	int t,i,j,p,q,temp,x;char m[121];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		p=0;q=0;
		gets(m);
		printf("%s",m);
		/*for(j=0;j<strlen(m);j++)
		{
			temp=(int)m[j];
			while(temp!=0)
			{
				if(temp%2==1)p++;
				q++;
				temp/=2;
			}
		}
		x=g(q,p);
		printf("%d/%d\n",p/x,q/x);*/
	}
}