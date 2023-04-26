#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	int T,dif,max_dif,times;
	long long int input;
	scanf ("%d",&T);
	times=0;
	while(T--)
	{
		int j=0;
		int in2[31]={'\0'};
		dif=1,max_dif=1; 
		scanf("%lld",&input);
		do{
			in2[j]=input%2;
			input/=2;
			j+=1;
		}while(input!=0);
		for (int i=1;i<j;i++)
		{
			if (in2[i]!=in2[i-1])
				dif+=1;
			else
				dif=1;
			if(dif>max_dif)
				max_dif=dif; 
		}
		printf("case #%d:\n%d\n",times,max_dif);
		times+=1;
	}	
}