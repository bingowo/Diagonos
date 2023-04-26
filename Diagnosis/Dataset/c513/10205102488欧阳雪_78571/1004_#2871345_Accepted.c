#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
void solveint(int n); //为何要分int double ：题目要求读入的数据要能在一个int 或double类型变量中存放
void solvedouble(double d);
int main()
{
	char s[31];
	while(scanf("%s",s)!=EOF)//连续输入多个字符串
	if(strchr(s,'.')==0)
	solveint(atoi(s));
	else solvedouble(atof(s));
	return 0;
 } 
 void solveint(int n){
 	int c=sizeof(n);
 	unsigned char*p=(unsigned char*)&n;//找到n的位置，逐个输出其以二进制形式存放的字节
 	while(c--)
 	printf("%02x ",*p++);//以十六进制输出（故定义p为char)%02x:每位以宽度为2输出
 	printf("\n");
 }
 void solvedouble(double d){
 	int c=sizeof(d);
 	unsigned char*p=(unsigned char*)&d;
 	while(c--)
 	printf("%02x ",*p++);
 	printf("\n");
 }