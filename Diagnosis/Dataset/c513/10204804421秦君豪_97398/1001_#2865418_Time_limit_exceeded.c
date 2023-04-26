#include <stdio.h>
#include<stdlib.h> 
#include<string.h>
void itob(long long int n,char* p,long long int b)
{
	long long int j,i=0;
	char a;
	int flag =0;
	if(n<0)
	{
		n=-1*n;
		flag=1;
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
	if (flag==1){
		*(p+i+1)='-';
		i++;
	}
	*(p+i+1)='\0';
}

int main()
{ 
	long long int T,N,i,R;
	char s[1000];
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		char *p;
		p=s;
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
