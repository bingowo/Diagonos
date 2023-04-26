#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	int T,a,j=0,p=0,temp;
	scanf("%d",&T);
	while(T--)
	{
		a=0,j=0,p=0,temp=0;
		char input[55]={'\0'},ans[155]={'\0'};
		scanf("%s",input);
		int numbers =0;
		int len=strlen(input)-1;
		for (;len!=1;--len){
			a=input[len]-'0';
			j=0;
			do{
				if (j<numbers)
					temp=a*10+input[j]-'0';
				else
					temp=a*10;
				ans[j++]=temp/8+'0';
				a=temp%8;
			}while(a!=0||j<numbers);
			numbers=j;
		}
		ans[numbers]='\0';
		printf("case #%d:\n0.",p);
		p+=1;
		for (int k=0;k<numbers;k++)
			printf("%c",ans[k]);
		printf("\n");
	}
}