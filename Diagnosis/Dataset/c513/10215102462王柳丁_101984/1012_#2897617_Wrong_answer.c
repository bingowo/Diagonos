#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char A[10000];
	scanf("%s",A);
	long long int a=0,b=0,r=0,q1=0,q2=0;
	int sign1=1,sign2=1,i=0;
	if(A[0]=='-'){sign1=-1;i++;}
	if(A[i]=='i')a=1;
	for(;(A[i]!='-')&&(A[i]!='+')&&(A[i]!='i')&&(i<strlen(A));i++)
	{
		a=a*10+A[i]-'0';
	}
	a=sign1*a;;
	if((A[i]=='i')&&(i==strlen(A)-1)&&(i!=0)){b=a;a=0;}//bi
	else if((A[strlen(A)-1]=='i')&&(A[strlen(A)-2]=='+')){b=1;}//a+i
	else if((A[strlen(A)-1]=='i')&&(A[strlen(A)-2]=='-')){b=-1;}//a-i
	else 
	{
		if(A[i]=='-')sign2=-1;
		for(i=i+1;(i<strlen(A))&&(A[i]!='i');i++)
		{
			b=b*10+A[i]-'0';
		}
		b=b*sign2;//a+bi
	}
	//printf("%lld %lldi",a,b);
	char res[10000]={'\0'};
	i=0;
	if((a==0)&&(b==0))res[i]='0';
	else
	{
		while((a!=0)||(b!=0))
		{
			if(abs(a%2)!=abs(b%2)){res[i]='1';r=1;}
			else {res[i]='0';r=0;}
			q1=(r-a+b)/2;
			q2=(r-a-b)/2;
			a=q1;
			b=q2;
			i++;
			//printf("(a=%d,b=%d)\n",a,b);
		}
	}
	char mid;
	for(i=0;i<strlen(res)/2;i++)
	{
		mid=res[i];
		res[i]=res[strlen(res)-1-i];
		res[strlen(res)-1-i]=mid;
	}
	printf("%s",res);
	return 0;
}
