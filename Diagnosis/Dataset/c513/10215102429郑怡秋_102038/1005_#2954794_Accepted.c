#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	char octal[55]={0},decimal[155]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",octal);
		int numbers=0,temp=0;
		int len=strlen(octal)-1;
		for(;len!=1;len--)
		{
			int digit=octal[len]-'0';
			int j=0;
			do{
				if(j<numbers) temp=digit*10+decimal[j]-'0';
				else temp=digit*10;
				decimal[j++]=temp/8+'0';
				digit=temp%8;
			}while(digit||j<numbers);
			numbers=j;
		}
		decimal[numbers]='\0';
		printf("case #%d:\n0.%s\n",i,decimal);
	}
	return 0;
}