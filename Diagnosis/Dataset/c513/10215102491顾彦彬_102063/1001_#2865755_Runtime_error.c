#include<stdio.h>
main()
{
	char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int T,N,R,i,sign=0,ans[32];
	scanf("%d",&T);
	for (int j=1;j<=T;j++)
	{	
		scanf("%d %d",&N,&R); 
		sign=1;
		i=0;
		if (N<0)
		{
			sign=-sign;
			N=-N;
			ans[i]="-";
			i++;
		}
		do
		{
			ans[i]=N%R;
			N=N/R;
			i+=1;
		}
	while(N);
	for (int k=0;k<=i;k++)
		{
			printf("%c",table[ans[k]]);
		}
	printf("\n");
	}
 } 