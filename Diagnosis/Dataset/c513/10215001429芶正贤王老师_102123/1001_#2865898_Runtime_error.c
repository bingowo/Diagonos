#include<stdio.h>
#include<string.h>
void ntor(int n,int r)
{
	int i = 0,sign,d,j;
	char c,s[100];
	
	if (n > 0)
	sign = 1;
	else
	{
		sign = -1;
		n = -n;
	}
	
	while(n > 0)
	{
		d = n%r;
		
		if(d < 10)
		s[i] = '0' + d;
		else
		s[i] = 'A' + d - 10;	
		
		i++;
		n = n/r;
	}
		if(sign < 0)
		s[i++] = '-';
		s[i] = '\0';
		for(i = 0,j = strlen(s) - 1;i < j;i++,j--)
		{
			c = s[j];
			s[j] = s[i];
			s[i] = c;
		}
		printf("%s\n",s);
}


int main()
{
	int T,i,N[100],R[100],j;
	scanf("%d",&T);
	getchar();
	for(i = 0;i < T;i++)
	{
		scanf("%d %d",&N[i],&R[i]);
		getchar();
	}
	for(j = 0;j < T;j++)
	ntor(N[i],R[i]);
	return 0;
}