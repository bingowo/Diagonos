#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int n,m,i=0;
	char a[26]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};
	char b[1000000];
	scanf("%d %d",&n,&m);
	if(n==0) printf("0");
	while(abs(n)>=1)
	{
		if(n%m<0)
		{
			b[i]=a[n-(n/m+1)*m];
			n=n/m+1;
			i++;
		}
		else
		{
			b[i]=a[n%m];
			n=n/m;
			i++;
		}
	}
	i--;
	while(i>=0)
	{
		printf("%c",b[i]);i--;
	}
	return 0;
	
	
 } 