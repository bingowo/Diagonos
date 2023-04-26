#include<stdio.h>
#include<string.h>

int main()
{
	//char table[17]="0123456789ABCDEF";
	char hex[100]={0},bin[400]={0};
	scanf("%s",hex);
	//十六进制转二进制
	
	long long int len = strlen(hex);
	int p=3;
	for(int i=2;i<len;i++)
	{
		if(hex[i]<='9' && hex[i]>='0')
		{
			int t=hex[i]-'0';
			for(int j=p;j>=p-3;j--)
			{
				bin[j]=t%2 + '0';
				if(t) t/=2;
			}
		}
		//if(hex[i]<='F' && hex[i]>='A')
		else
		{
			int t=hex[i]-'A'+10;
			for(int j=p;j>p-4;j--)
			{
				bin[j]= t%2 + '0';
				if(t)	t/=2;
			}
		}
		p+=4;
	}
	
	//i-1进制转十进制
	len = (len-2)*4;
	bin[len]='\0';
//	printf("%s\n",bin);
	long long int qr=0,qi=0,a,b;
	for(int i=0;i<len;i++)
	{
		int r = bin[i] - '0';
		a = - qr - qi + r;
		b = qr - qi;
		qr = a,qi = b;
	}
	//输入结果
	if(qr)
	    printf("%lld",qr);
	if(qi > 0)
	{
		if(qi==1)
			printf("+i\n");
		else
			printf("%+lldi\n",qi);
	}
	else if(qi < 0)
	{
		if(qi==-1)
			printf("-i\n");
		else
			printf("%lldi\n",qi);
	}
	else
		printf("\n");
	return 0;
}
