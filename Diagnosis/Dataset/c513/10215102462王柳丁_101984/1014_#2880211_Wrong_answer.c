#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int A,B,i,n;
	char a;
	char num[10000];
	scanf("%d %d",&A,&B);
	//转化成普通三进制数
	int C=A/B; //C为整数部分 
	A=A-C*B;//小数部分变为A/B
	if(C>0){
		while(C>0)
		{
			num[i]=C%3+'0';
			C=C/3;
			i++;
		}
		
		n=strlen(num);
		for(i=0;i<n/2;i++)
		{
			a=num[i];
			num[i]=num[n-i-1];
			num[n-i-1]=a;
		}
		if(A>0)num[n]='.';
	}
	else {
		num[0]='0';
		if(A>0)num[1]='.';
	}//储存了整数部分以及小数点
	if(A>0)
	{
		i=strlen(num); 
		int b=3;
		while(A>0&&b<=B)
		{
			num[i]='0';
			while(((num[i]-'0')*B/b)<=(A-B/b)&&num[i]<'3')num[i]++;;
			A=A-(num[i]-'0')*B/b;
			b=b*3;
			i++;
		}//储存小数位 
	}
	printf("%s\n",num);//普通三进制储存
	char num1[10000];
	for(i=0;i<strlen(num);i++)
	{
		if(num[i]=='.')num1[i]='.';
		else num1[i]='1';
	 } 
	 printf("%s\n",num1);
	char num2[10000];
	n=strlen(num);
	int eve,add=0;
	for(i=0;i<n;i++)
	{
		if(num[n-i-1]=='.'){num2[n-i-1]='.';
		}
		else{
			eve=0;
			eve=(num[n-i-1]-'0')+(num1[n-i-1]-'0')+add;
			num2[i]=eve%3+'0';	
			if(eve>2){
				add=eve/3;
			}
			else add=0;	
		}	
	}
	n=strlen(num);
	for(i=0;i<n/2;i++)
		{
			a=num2[i];
			num2[i]=num2[n-i-1];
			num2[n-i-1]=a;
		}
	printf("%s\n",num2);
	
}