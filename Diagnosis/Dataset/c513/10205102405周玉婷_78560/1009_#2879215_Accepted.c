//用指针访问数组元素 
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
    scanf("%d",&t);
    char c=getchar();
    for(int i=0;i<t;i++)
    {   char s[121];
    	gets(s); 
    	int numof1=0;
    	unsigned char *p=(unsigned char *)s;
    	while(*p)//*p指向0结束 
    	{
    		unsigned char n=*p++;
    		do{if(n%2) numof1++;}
    		while(n/=2);
		}
		int den=sizeof(char)*strlen(s)*8;
		int max=gcd(numof1,den);
		printf("%d/%d\n",numof1/max,den/max);
	}
	return 0;	
}