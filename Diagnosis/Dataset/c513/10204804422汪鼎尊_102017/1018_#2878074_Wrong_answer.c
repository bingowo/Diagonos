#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int primes[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113};

void fmt(int* arr)
{
	int i;
	for(i=0;i<49;i++)if(arr[i]>=10)
	{
		arr[i+1]+=arr[i]/10;
		arr[i]=arr[i]%10;
	}
}

void multiply(int* dest,int multiplier)
{
	int i;
	for(i=0;i<50;i++)dest[i]=dest[i]*multiplier;
}

int main()
{
	int input[30],result[50];
	int i=0,j=0,len=0;
	char ch;

	memset(input,0,30*sizeof(int));
	memset(result,0,50*sizeof(int));
	
	while(1){
		scanf("%d",&j);
		for(i=29;i>0;i--)input[i]=input[i-1];
		input[0]=j;
		len++;
		scanf("%c",&ch);
		if(ch!=',')break;
	}
	
	for(len--;len>=0;len--)
	{
		multiply(result,primes[len]);
		result[0]+=input[len];
		fmt(result);
	}
	
	
	
	for(len=49;result[len]==0;len--);
	for(;len>=0;len--)
	{
		printf("%d",result[len]);
	}
	return 0;
}