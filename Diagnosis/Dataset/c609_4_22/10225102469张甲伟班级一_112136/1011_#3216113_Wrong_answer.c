#include<stdio.h>
#include<stdlib.h>
char s[100];
int cnt1,cnt2,tap1,tap2;
int A,B,C;
int main()
{
	int i=0,j;
	for(i=0;scanf("%c",&s[i])==1;i++)
	{
		if(s[i]=='.')
			break;
	}
	tap1=i;cnt1=i;
	i++;
	for(j=i;scanf("%c",&s[j])==1;j++)
		;
		//printf("%s",s);
	cnt2=j-cnt1-2;
	tap2=j-2;
		//printf("%d %d %d %d\n",cnt1,tap1,cnt2,tap2);
	for(i=0;i<tap1;i++)
	{
		if(s[i]=='2')
			A=A*3-1;
		else
			A=A*3+(s[i]-'0');
	}
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
	return 0;
 } 