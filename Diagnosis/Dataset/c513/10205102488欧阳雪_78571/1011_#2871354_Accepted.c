#include<stdio.h>
#include<string.h> 
int SixTtoTwo(char *s,int *t,int k)
{
	for(int i=2;i<strlen(s);i++)
	{
		int d;
		if(s[i]>='A')d=s[i]-'A'+10;
		else d=s[i]-'0';
		unsigned int flag=0x8;
		while(flag)
		{
			if(d&flag)t[k++]='1';
			else t[k++]='0';
			flag=flag>>1;
		}	
	}
	return k;
}
int main()
{
	char s[1000]={0};
	scanf("%s",s);
	int t[1000]={0},k=0;//存放S转换后的二进制
	k=SixTtoTwo(s,t,k);
	long long int qr=0,qi=0;
	long long int a,b;
	for(int j=0;j<k;j++)//求复整数 
	{
		int r=t[j]-'0';
		a=-qr-qi+r;
		b=qr-qi;
		qr=a;
		qi=b;
	}
	if(qi==0)//输出，无虚部
	{
		printf("%lld\n",qr);
	 }
	 else
	 {
	 	if(qr!=0)//有实部
		 {
		 	printf("%lld",qr);
		 	if(qi>0)printf("+");
		  }
		if(qi==1)printf("i\n");
		else if(qi==-1)printf("-i\n");
		else{
			printf("%lld",qi);
			printf("i\n");
		}
	 }
}