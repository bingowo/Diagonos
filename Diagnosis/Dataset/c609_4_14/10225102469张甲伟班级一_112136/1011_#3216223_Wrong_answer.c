#include<stdio.h>
#include<stdlib.h>
char s[100];
int cnt1,cnt2,tap1,tap2;
int A,B,C,signal;
int main()
{
	int i=0,j;
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='.')
		{
			signal++;
			break;
		}
	}
	tap1=i;cnt1=i;
	for(i=0;i<tap1;i++)
	{
		if(s[i]=='2')
			A=A*3-1;
		else
			A=A*3+(s[i]-'0');
	}
	if(signal)
	{
		for(j=tap1;s[j]!='\0';j++)
		;
		//printf("%s",s);
	cnt2=j-cnt1-1;
	tap2=j-1;
		//printf("%d %d %d %d\n",cnt1,tap1,cnt2,tap2);
	int t=cnt2;
	C=1;
	while(t)
	{
		C*=3;
		t--;
	}
	for(i=tap1+1;i<=tap2;i++)
	{
		if(s[i]=='2')
			B=B*3-1;
		else
			B=B*3+(s[i]-'0');
	}
	//printf("%d\n",B);
	if(A*B<0)
	{
		if(A<0)
			A++;
		else
			A--;
		B=C-abs(B);
	}
	if(A!=0)
	{
		printf("%d ",A);
		if(B>0)
			printf("%d %d",B,C);
	}
	else
		printf("%d %d",B,C);
	}
	else
		printf("%d ",A);
	return 0;
 } 