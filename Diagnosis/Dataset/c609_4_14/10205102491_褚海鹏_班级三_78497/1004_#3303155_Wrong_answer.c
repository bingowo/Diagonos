#include<stdio.h>
char s[]="0123456789ABCDEF";
int trans(int n,int r)
{
	if(n)
	{
		int c=n/r;
		trans(c,r);
		printf("%c",s[n%r]);
	}
	
	
}
int main()
{
	int A,B;
	char n[100];
	int result=0; 
	scanf("%d%s%d",&A,&n,&B);
	for(int i=0;n[i];i++)
	{
		result=result*A;
		if(n[i]=='a'||n[i]=='A')result=result+10;
		else if(n[i]=='b'||n[i]=='B')result=result+11;
		else if(n[i]=='c'||n[i]=='C')result=result+12;
		else if(n[i]=='d'||n[i]=='D')result=result+13;
		else if(n[i]=='e'||n[i]=='E')result=result+14;
		else if(n[i]=='f'||n[i]=='F')result=result+15;
		else result=result+n[i]-'0';
	}
	printf("%d\n",result);
	trans(result,B);
	return 0;
}