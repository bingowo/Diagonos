#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char s[31]={0};
	scanf("%s",s);
	int i=0;
	int flg1=0;//标记整数、小数 
	while(s[i]!='.'&&s[i]!='\0')
	{
		i++;
	}
	if(s[i]=='\0')//没有小数部分 
	{
		flg1=1;
	}
	long long int z=0;
	int temp=0,t=i-1,j=0;
	while(j<i)
	{
		if(s[j]=='1')
		{
			z=z+pow(3,t);
		}
		if(s[j]=='2')
		{
			z=z-pow(3,t);
		}
		j++;
		t--;
	}
	if(flg1==1)
	{
		printf("%d",z);
		return 0;
	}
	
	int k=0;
	k=strlen(s)-i-1;//小数位数 
	long long int fm=pow(3,k);
	long long int fz=0;
	i++;
	t=1;
	while(s[i]!='\0')
	{
		if(s[i]=='1')
		{
			fz=fz+fm/pow(3,t);
		}
		if(s[i]=='2')
		{
			fz=fz-fm/pow(3,t);
		}
		i++;
		t++;
	}
	
//	printf("z:%d\n",z);
	long long int A=0,B=0,C=0;
	fz=z*fm+fz;
//	printf("fz:%d\n",fz); 
	A=fz/fm;
	B=fz%fm;
	C=fm;
	//printf("B:%d\n",B);
	if(fz<0&&A!=0)
	{
		B=-B;//让A为负数 
	}
	if(A!=0)
	{
		printf("%lld ",A);
		printf("%lld ",B);
		printf("%lld ",C);
	 } 
	else
	{
		if(B!=0)
		{
			printf("%lld ",B);
			printf("%lld",C);
		}
		else{
			printf("0");
		}
	}
}