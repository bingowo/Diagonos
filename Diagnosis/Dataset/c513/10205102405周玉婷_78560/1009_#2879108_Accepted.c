#include<stdio.h>
#include<string.h>
int gcd(int a,int b)
{
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
int main()
{
	int t;
    scanf("%d",&t);//输入次数 
    char c=getchar();
    for(int i=0;i<t;i++)
    {   //char c=getchar();//**********************之前把getchar（）放这，好像gets()可以自动跳过换行符，
    	//等待下一次输入字符流
    	char s[121];
    	gets(s);
    	/*for(int k=0;s[k];k++)
    	{
    		printf("%c\n",s[k]);
		}************************************用于检测输入情况*/ 
    	int numof1=0;
    	unsigned char *p=(unsigned char *)s;
    	for(int j=0;j<strlen(s);j++)//while(*p)//*p指向0结束 
    	{
    		//printf("%d\n",strlen(s));检测汉字占的字节数 
    		unsigned char n=s[j];
    		//unsigned char n=*p++;//能否写成unsigned char n=s[j],不用指针 
    		do{if(n%2) numof1++;}
    		while(n/=2);
		}
		int den=sizeof(char)*strlen(s)*8;
		int max=gcd(numof1,den);
	//	double result=1.0*num1/(sizeof(char)*strlen(s)*8);//注意/的用法
	//	printf("%lf\n",result);
	//printf("%d\n",num1);
		printf("%d/%d\n",numof1/max,den/max);
	}
	return 0;
	//负数的取余运算， 
	
}