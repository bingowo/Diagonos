#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	char input[31];
	int location_point=-1,A,B,C=1,weight=1,weight2=1,i=0;
	scanf("%s",input);
	for (i;input[i];i++)
	{
		if (input[i]=='.')
			location_point=i;
	}
	if (i==-1)
		location_point=strlen(input);
	for (int i=location_point-1;i>=0;i--)
	{
		A=A+weight*(-input[i]+'1');
		weight=weight*3;
	}
	if (location_point=strlen(input))
	{
		printf("%d",A);
		return 0;
	}
	for (int j=strlen(input)-1;j>location_point;i--)
	{
		C=C*3;
		B=(-input[j]+'1')*weight2+B;
		weight2*=3;
	}
	if(B<0)
	{
		A=A-1;
		B=C+B;
	} 
	while(B%3==0)
	{
		B/=3;
		C/=3;
	}
	printf("%d %d %d",A,B,C);
}