#include<stdio.h>
#include<string.h>
main()
{
	long long int c,d,m,n,x,list[100000],num;
	char input[100000];
	scanf ("%s",input);
	m=1;
	n=1;
	for (int i=2;input[i];i++)
	{
		if (input[i]<'A')
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
	for (int i=0;i<4*m-4;i++)
	{
		//printf("%lld",list[i]);
		x=c;
		c=list[i]-c-d;
		d=x-d;
	}
	if  (c==0)
		{
				if (d==1)
						printf("i");
					else if(d==0)
						printf("0");
					else if (d==-1)
						printf("-i");
						else
						printf("%lldi",d);
		}
	else if (d==0)
		printf("%lld",c);
	if (d>0&&c!=0){
		if (d==1)
			printf("%lld+i",c);
		else
			printf("%lld+%lldi",c,d);
	}
	if (d<0&&c!=0)
	{
		if (d==-1)
			printf("%lld-i",c);
		else
			printf("%lld-%lldi",c,-d);
	}
}

