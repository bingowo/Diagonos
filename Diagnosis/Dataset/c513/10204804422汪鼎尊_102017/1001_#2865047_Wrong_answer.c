#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char t(int i)
{
	return i<9?i+'0':i-10+'A';
}

int main()
{
	long long int n;
	int r,i,j,cases,c,p,n1;
	char result[100];
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		p=0;n1=0;
		scanf("%lld %d",&n,&r);
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		if(n<0)
		{
			n=-n;
			n1=1;
		}
		for(;n!=0;n=n/r)result[p++]=t(n%r);
		//result[p]='\0';
		//printf("%s\n",result);
		if(n1==1)putchar('-');
		for(p--;p>=0;p--)putchar(result[p]);
		putchar('\n');
	}
	
	
	return 0;
}