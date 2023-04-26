#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//int primes[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113};

int main()
{
	int input,base;
	char result[30];
	int i,j,len=0;
	scanf("%d %d",&input,&base);
	
	while(input!=0)
	{
		i=input%base;
		if(i<0)i=i-base;
		input-=i;
		input/=base;
		result[len]=(i>=10?i-10+'A':i+'0');
		//printf("%d %d\n",i,(i>=10?i-10+'A':i+'0'));
		len++;
	}
	for(len--;len>=0;len--)putchar(result[len]);
	
	
	
	
	
	return 0;
}