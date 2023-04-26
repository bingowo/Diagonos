#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
void trans(char*p,long N,int R)
{
	int m;
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
	int T,a,b,len,i;char s[100];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%ld%d",&a,&b);
		trans(s,a,b);
		len=strlen(s);
		for(i=0;i<len;i++)
		printf("%c",s[i]);
		printf("\n");	
	}
	
	
	return 0;
}