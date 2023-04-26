#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	char input[501],num[6000];
	int x[200],a,n,l,count;
	scanf ("%s",input);
	count=0;
	int j=0;
	for (int i=0;input[i];i++)
	{
		count+=1;
		if(count==3){
			count=0;
			x[j]=100*num[i-2]+10*num[i-1]+num[i];
			j+=1;
		}
	}
	num[0]='0',num[1]='0',num[2]='0',num[3]='1';
	int len=strlen(input);
	char z[10]={};
	a=0
	do{
	z[9-a]=len%2+'0';
	len=len/2;
	a+=1;
	}while(len)
	for (l=0;l<9-len;l++)
	{
		num[4+l]='0';		
	}
	for (n;z[n];n++)
	{
		num[4+l]=z[n];
		l++;
	}
	
	//最后1或2个数的判断
		n=0;
		a=0;
	for (int k=0;x[k];k++){
		char y[10]={};
		do
		{
		y[9-a]=x[k]%2+'0';
		x[k]=x[k]/2;
		a+=1;
		}while(x[k]);
		for (l=0;l<10-a;l++)
			num[14+l+10*k]='0';
		for (n;y[n];n++){
			num[14+l+10*k]=y[n]+'0';
			l++;
		}
		a=0;
		n=0;
	}

	for(int m=0;num[m];m++)
		printf("%c",num[m]);
 } 