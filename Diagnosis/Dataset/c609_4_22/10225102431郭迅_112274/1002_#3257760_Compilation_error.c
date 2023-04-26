#include<stdio.h>
void f(int n,char s[])
{
	if(n/2){f(n/2,s);
	}
	s[j++]=n%2+'0';
	s[j]='\0';
}
int main()
{
	int t;scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;char s[32];
		scanf("%d",n);
		f(n,s);
		int ret=1,m=1;
		for(int j=0;j<31;j++){
			if(s[j+1]!=s[j])m++;
			else if (m>ret){ret=m;m=1;
			}
			else m=1;
		}
		printf("case #%d:\n%d\n",i,ret);
	}
}