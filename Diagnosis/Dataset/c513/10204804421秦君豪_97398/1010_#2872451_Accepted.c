#include <stdio.h>
#include<stdlib.h> 
#include<string.h>
void rub(char *p,int N)
{
	int k=0;
	for (k=0;k<N;k++)
	{
		*(p+k)='0';
//		printf("%d\n",p);
	}
}

int main()
{ 
	long long int n=0,i,j,k,cout1=0,cout0=0,len=0;
	char *s=(char*)malloc(sizeof(char)*510);
	char *s1=(char*)malloc(sizeof(char)*2000);
	char s10[11]="0000000000"; 
	s1[0]='0';
	s1[1]='0';
	s1[2]='0';
	s1[3]='1'; 
	char s4[5]="0000";
	char s7[8]="0000000";
	scanf("%s",s);
	len=strlen(s);
	for (i=9;i>=0;i--)
	{
		s10[i]=len%2+48;
		len=len/2;
	}
	strcat(s1,s10);
	rub(s10,10);
	for (i=0;i<strlen(s);i=i+3)
	{
		if (strlen(s)-i==1) 
		{
			n=s[i]-48;
			for (j=3;j>=0;j--)
			{
				s4[j]=n%2+48;
				n=n/2;
			}
			strcat(s1,s4);
			rub(s4,4);
		}
		else if(strlen(s)-i==2)
		{
			n=(s[i]-48)*10+s[i+1]-48;
			for (j=6;j>=0;j--)
			{
				s7[j]=n%2+48;
				n=n/2;
			}
			strcat(s1,s7);
			rub(s7,7);
		}
		else 
		{
			n=(s[i]-48)*100+(s[i+1]-48)*10+(s[i+2]-48);
			for (j=9;j>=0;j--)
			{
				s10[j]=n%2+48;
				n=n/2;
			}

			strcat(s1,s10);
		}
		
			
//		printf("s10=%s\n",s10);
		
	}

	printf("%s",s1);
	free(s);
	return 0;//
} 