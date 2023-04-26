#include<stdio.h>
#include<string.h>
main()
{
	long long int c,d,m,n,x,list[100000],num;
	char input[100000];
	scanf ("%s",input);
	//for (int i=0;i<(strlen(input)-2)*4;i++)
		//list[i]=0;
	m=1;
	n=1;
	for (int i=3;input[i];i++)
	{
		if (input[i]>='0')
			num=input[i]-'0';
		else
			num=input[i]-'A'+10;
		for (n=1;n<=4;n++)
		{
			list[4*m-n]=num%2;
			num=num/2;
		}
		m+=1;
	}
	c=0;
	d=0;
	for (int i=0;list[i];i++)
	{
		x=c;
		c=list[i]-c-d;
		d=x-d;
	}
	printf("%lld+%lldi",c,d);
}