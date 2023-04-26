#include <stdio.h>
#include <stdlib.h>

int conver(int n,int r)
{
	int sign=0;
	if(n<0){n=-n;sign=1;
	}
	char numb[100];
	int i=0,a;
	char t;
	do
	{
		a=n%r;
		if(a<10)numb[i]='0'+a;
		if(a>9)numb[i]='A'+a-10;
		n=n/r;
		i++;
	}while(n>0);
	if(sign==1)printf("-");
	for(i=i-1;i>=0;i--)
	{
		printf("%c",numb[i]);
	}
	return 0;
}

int main() {
	int t,i=0;
	scanf("%d",&t);
	int n[t],r[t];
	for(;i<t;i++)
	{
		scanf("%d %d",&n[i],&r[i]);
		
	}
	for(i=0;i<t;i++)
	{
		conver(n[i],r[i]);
		printf("\n");
	}
	return 0;
}