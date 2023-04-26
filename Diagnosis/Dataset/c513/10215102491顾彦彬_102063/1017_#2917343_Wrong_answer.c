#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	int table[127]={},sign[10000];
	for (int i=0;sign[i];i++)
		sign[i]=1;
	table['I']=1;
	table['V']=5;
	table['X']=10;
	table['L']=50;
	table['C']=100;
	table['D']=500;
	table['M']=1000;
	table['(']=0;
	table[')']=0;
	char input[10000];
	scanf("%s",input);
	long long int ans=0,times=1;
	//int len=strlen(input); 
	for (int i=0;input[i+1];i++)
	{
		if (table[input[i]]<table[input[i+1]])
			sign[i]=-1;
	}
	for (int i=0;input[i];i++)
	{
		if (input[i]='(')
			times*=1000;
		if (input[i]=')')
			times/=1000;
		ans=ans+table[input[i]]*sign[i]*times;
	}
	printf("%lld",ans);
}