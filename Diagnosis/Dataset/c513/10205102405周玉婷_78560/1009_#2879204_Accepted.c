//直接访问数组元素 
#include<stdio.h>
#include<string.h>
/*对于同一个二进制储存，数据类型不同读取结果值不同，汉字要占用2~3个bytes，为了读出其二进制，
要用unsigned char去读，得到一个无符号整数，该整数的二进制与储存汉字的某一个字节二进制情况一样*/ 
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
    {   /*char c=getchar();*************之前把getchar（）放这，gets()可以自动跳过换行符，
	    等待下一次输入字符流，这样得到上一轮结果后如果直接输入，第一个字符会被getchar吃掉 */ 
    	char s[121];
    	gets(s);
    	int numof1=0;
    	for(int j=0;j<strlen(s);j++) 
    	{
    		unsigned char n=s[j];
			/*这个好奇怪，能把char *指针指向的内容转换成unsisned char,
		    是不是s[j]指向的内存区以unsigned char 的数据类型去读？就像
			把类型为char *s的指针强制转换成unsigned char*s */ 
    		do{if(n%2) numof1++;}
    		while(n/=2);
		}
		int den=sizeof(char)*strlen(s)*8;
		int max=gcd(numof1,den);
		printf("%d/%d\n",numof1/max,den/max);
	}
	return 0;	
}