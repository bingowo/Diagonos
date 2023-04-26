#include<stdio.h>
#include<stdlib.h>
#include<string.h>


main()
{
	int M,N,table[32];
	char input[32];
	scanf("%d",&M);
	scanf("%s",input);
	scanf("%d",&N);
	int len=strlen(input);
	if(len==1&&input[0]=='0')
	{
		printf("0");
	}
	else{
	for(int i=0;i<len;i++)
	{
		if(input[i]>='a'&&input[i]<='z')
		{
			table[i]=input[i]-'a'+10;
		}
		if(input[i]>='A'&&input[i]<='Z')
		{
			table[i]=input[i]-'A'+10;
		}
		if(input[i]>='0'&&input[i]<='9')
		{
			table[i]=input[i]-'0';
		}		
	}
	long long int val=0,k=0;
	for(int i=len-1;i>=0;i--)
	{
		long long int x=1;
		for (int j=0;j<k;j++)
		{
			x*=M;
		}
		k++;
		val+=table[i]*x;
	}
	int res[32],j=0;
	while(val>0)
	{
		res[j++]=val%N;
		val=(val-(val%N))/N;
	}
	for(j=j-1;j>=0;j--)
	{
		if(res[j]>=0&&res[j]<=9)
			printf("%d",res[j]);
		else printf("%c",res[j]+'A'-10);
	}
}
}