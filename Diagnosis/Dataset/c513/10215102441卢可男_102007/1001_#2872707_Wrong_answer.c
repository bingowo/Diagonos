#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
void trans(char*p,long N,int R)
{
	int m;
	if(N<0){N=-N;}
	while(N)
	{
		m=N%R;
		if(m<10){*p=m+48;}
		else {*p=m+55;}
		N=N/R;
		p++;	
	}
	*p='\0';
		
}
int main() 
{
	int T,b,len,i,Q=1;char s[100];
	long a;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%ld%d",&a,&b);
		if(a<0){Q=0;}
		trans(s,a,b);
		len=strlen(s);
		if(Q==0)printf("-");
		for(i=len-1;i>=0;i--)
			printf("%c",s[i]);
			printf("\n");
			
	
	}
	
	
	return 0;
}