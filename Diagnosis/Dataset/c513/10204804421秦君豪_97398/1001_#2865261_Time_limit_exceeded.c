#include <stdio.h>
#include<string.h>
void itob(int n,char* p,int b)
{
	int j,i=0;
	char a;
	int flag = 0;
	if(n<0)
	{
		n=-1*n;
		flag = 1;
	}
	while (1)
	{
		j=n%b;
		n=n/b;
		if(j>=10) a='A'+j-10;
		else a='0'+j;
		*(p+i)=a;
		if(n==0) break;
		i++;
	}
	if (flag)
	{
		*(p+i+1)='-';
		i++;
	}
	*(p+i+1)='\0';
}

int main()
{ 
	long long int T,N,i,R;
	char s[100];
	char *p;
	p=s;
//	const char* num[]={'A','B','C','D','E','F','G'};
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%lld%lld",&N,&R);
		itob(N,p,R);
		for(i=strlen(s)-1;i>=0;i--)
		{
			printf("%c",s[i]);
		}
		printf("\n");
	} 
	 
     return 0;
}
