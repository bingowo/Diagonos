#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long a,b,l;
char s[1005],ans[10005];
int main()
{
	//读取复数部分
	scanf("%s",s);
	l=strlen(s);
	if(s[l-1]!='i')a=atoll(s),b=0;//没有虚数部分
	else
    {
		for(int i=l-1;i>=0;i--) //从后往前读，先读虚数部分，不用记录几个符号
			if(s[i]== '+'||s[i]=='-'||i==0)
			{ 
				if(s[i+1]=='i')b=s[i] =='+'?1:-1;//单独一个+,-i的情况
				else if(s[i]=='i')b=1;//只有i的情况
				else s[l-1]='\0',b=atoll(s+i);//插入\0，使用C函数读入虚数部分

				if(i!=0)s[i]='\0',a=atoll(s);//同上，读入实数部分
				else a=0;//不存在实数部分 
				break;
			}
	}
	//转换部分
	int top=0;
	while(a!=0||b!=0)
    {
		long long lasa=a,lasb=b;
		if((a-b)%2==0)ans[++ top]='0',a=(lasa - lasb)/-2,b=(lasa + lasb)/-2;
		else ans[++top]='1',a=(lasa - lasb - 1)/-2,b=(lasa+lasb-1)/-2;//题目给的计算方法
	}
	if(top == 0) puts("0");
	while(top) printf("%c", ans[top --]);//从高位到低位输出
	return 0;
}