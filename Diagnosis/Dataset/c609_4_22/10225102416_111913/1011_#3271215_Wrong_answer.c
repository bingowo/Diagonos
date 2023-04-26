#include<stdio.h>

int main()
{
	int number;
	scanf("%d",&number);
	int a[100];
	int i=99;
	do{
		a[i--]=number%3;
	}while(number/=3);
	
	int flag=0;   //记录进位
	for(int j=99;j>i;j--)
	{
		if(a[j]+flag==2)    
		{
			a[j]=2;
			flag=1;
		}
		else if(a[j]+flag==1)
		{
			a[j]=a[j]+flag;
			flag=0;
		}
		else if(a[j]+flag==3)
		{
			a[j]=0;
			flag=1;
		}
	}
	if(flag==1)
	{
		a[i]=1;
		for(int j=i;j<100;j++)
		{
			printf("%d",a[j]);
		}
	}
	else{
		for(int j=i+1;j<100;j++)
		{
			printf("%d",a[j]);
		}
	} 
	return 0;
}
