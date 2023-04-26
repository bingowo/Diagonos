#include<stdio.h>
#include<string.h> 
#define outer 0 //外层状态
#define paren 1 //小括号状态
#define brack 2 //中括号状态
#define brace 3 //大括号状态
#define filled_brack 4
#define filled_brace 5
int judge(char*str)
{
	int len=strlen(str),states[1000],top=0;
	states[top]=outer;
	for(int i=0;i<len;i++)
	{
		int state=states[top];
		char ch=str[i];
		if(state==outer){
			if(ch=='('){
				states[++top]=paren;
				continue;
			}
			if(ch=='['){
				states[++top]=brack;
				continue;
			}
			if(ch=='{'){
				states[++top]=brace;
				continue;
			}
			else return 0;
		}
		if(state==paren){
			if(ch=='{')
			{
				states[++top]=brace;
				continue;
			}
			if(ch==')')
			{
				top--;
				if(states[top]==outer){
					continue;
				}
				states[top]=filled_brack;
				continue;
			}
			else return 0;
		}
		if(state==brack||state==filled_brack)
		{
			if(ch=='(')
			{
				states[++top]=paren;
				continue;
			}
			if(ch==']')
			{
				if(state==brack)return 0;//说明中括号里是空的
				//不为空则要标记不为空状态 
				top--;
				if(states[top]==outer){
					continue;
				} 
				states[top]=filled_brace;
				continue;
			}
			else return 0;
		}
		if(state==brace||state==filled_brace)
		{
			if(ch=='[')
			{
				states[++top]=brack;
				continue;
			}
			if(ch=='}')
			{
				if(state==brace)//说明为空 
				{
					return 0;
				}
				//不为空则标记状态
				top--;
				continue;
			}
			else return 0;
		}
	}
	return states[top]==outer; 
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char str[101]={0};
		scanf("%s",str);
		printf(judge(str)?"Yes\n":"No\n");
	}
	return 0;
 }