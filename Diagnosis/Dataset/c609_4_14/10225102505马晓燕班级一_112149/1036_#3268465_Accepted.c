#include<stdio.h>
#include<string.h>

//方法一、最直观的方法是使用栈，一个栈stack存当前'('的括号，一个栈score存当前括号'（‘包含的子括号的分数，默认为0（没有子括号）
//score提前入栈一个元素0作为初始值，也是保存最终值。
//
//1、遍历字符串，当遇到'('则入栈stack，score入栈0。
//
//2、当遇到')'则，如果score的当前栈顶元素为0，则出栈0，stack出栈，前一个元素score分数加1;
//如果栈顶元素不为0，则前一个元素加上2*栈顶元素值，然后score出栈，stack出栈。
//这里不用考虑score的前一个元素下标未-1越界，因为一开始就入栈了一个元素0.来保存()前一个元素的值。
//——————————————————————————————————————————————

int main()
{
	int i=0,j=0,temp[50]={0};
	char s[52]={0};
	scanf("%s",s);
	char stack[50]={0};
	int len = strlen(s);
	//stack[j]=s[i++];
	while(i<len)
	{
		if(s[i] =='(')
		{
			++j;			//表示站内当前元素下标
			stack[j]='(';	//当前括号
			temp[j]=0;		//无子括号
		}else 
		{
			if(stack[j] == '(')//匹配上了
			{
				if(temp[j] == 0)	//1.尾端状态为无子括号
				{
					stack[j]=0;		//stack.pop_back
					temp[j]=0;		//temp.pop_back
					j--;
					temp[j] += 1;	//最外侧+1（A+B）
				}else
				{
					int sco = 2 * temp[j];//2.(A) score= 2*A
					stack[j]=0,temp[j]=0;
					j--;
					temp[j] = temp[j] + sco;
				}
			}
		}
		i++;
	}
	printf("%d\n",temp[0]);
	
	return 0;
}