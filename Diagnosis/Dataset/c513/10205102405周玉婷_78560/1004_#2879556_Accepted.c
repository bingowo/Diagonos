#include<stdio.h>
#include<stdlib.h>
void chang1(double n)
{
	int m=sizeof(double);
	unsigned char *p=(unsigned char *)&n;
	while(m--)
	{
		printf("%02x%c",*p++,m==0?'\n':' ');
	}
 } 
 void chang2(int n)
{
	int m=sizeof(int);
	unsigned char *p=(unsigned char *)&n;
	while(m--)
	{
		printf("%02x%c",*p++,m==0?'\n':' ');
	}
 } 
int main()
{
	char s[315];
	while(scanf("%s",s)!=EOF)//老师说的 
	{
		char* p=s;
		/*判断是否有小数点还可以学习大佬写的：#include<string.h> if（strchr(s,'.') change1(atob(s))）
		else change2(atoi(s));*/ 
		int flag=0;
		while(*p)
		{
			if(*p=='.') {flag=1;break;}
			p++;	
		}
		if(flag==1)  chang1(atof(s));   
		else chang2(atoi(s));       
		/*之前想写change1,仅仅把n换为题目要求的数组，即在main函数创建数组a，在change1函数中
		把n转换成题目要求的形式放到数组a中，再在主函数中按要求形式输出把每组数据然后再返回
		给主函数，再有主函数输出；但题目里只要求输出即可，故直接在change1函数中输出即可 */ 
	}
}