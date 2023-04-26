#include<stdio.h>
#include<string.h>
int TenToR(int b[10],long long num,int r,int flg)//十进制转R进制（不包括十六进制，不包括负数） 
{
    long long c;
    int a[10];
    int i=0,j=0;
    while (num>0)
    {
        c = (num % r);
        a[i] = c;
        num = num / r;
        i++;
    }
    for (i--,j=0;i >= 0; i--,j++) //返回的b[]存储答案
	{
		b[j]=a[i];
//		printf("%d",b[j]);
	}
//	printf("\n");
	int t=0;
	if(j<10&&flg==10)
	{
		t=10-j;
		for(i=0;i<t;i++)
		{
			printf("0");
		}
	}
	if(j<4&&flg==4)
	{
		t=4-j;
		for(i=0;i<t;i++)
		{
			printf("0");
		}
	}
	if(j<7&&flg==7)
	{
		t=7-j;
		for(i=0;i<t;i++)
		printf("0");
	}
	
	for(i=0;i<j;i++)
	{
		printf("%d",b[i]);
	}       
	//return j;//答案的位数
}
int main()
{
	char s[501]={0};
	scanf("%s",s);
	printf("0001");
	int len=strlen(s);
	int b[10]={0};
	TenToR(b,len,2,10);
	int i=0,temp=0,j=0;
	for(j=0;j<len/3;j++)
	{
		temp=0;
		for(int t=0;t<3&&s[i]!='\0';t++)
		{
			temp*=10;
			temp+=(s[i]-'0');
			i++;
		}
		memset(b,0,10);
		TenToR(b,temp,2,10);
	}
	if(len%3==1)
	{
		memset(b,0,10);
		TenToR(b,s[len-1],2,4);
	}
	if(len%3==2)
	{
		memset(b,0,10);
		temp=0;
		temp+=(s[len-2]-'0');
		temp*=10;
		temp+=(s[len-1]-'0');
		TenToR(b,temp,2,7);
	}
}
