#include<stdio.h>
#include<stdlib.h>
int S[50] = {0};  //使用数组模拟栈
int T = 0;
void S_init()//初始化栈
{
	T = 0;
	memset(S, 0, sizeof(S));
}
void S_push(int num)//入栈
{
	S[T++] = num;
}
int S_pop()//出栈
{
	int num = S[T - 1];
	S[--T] = 0;
	return num;
}
int F(char S[])
{
	S_init();
	S_push(0);
	for(int i = 0; i < strlen(S); i++)
	{
		if (S[i] == '(') S_push(0);
		else
		{
			int c1 = S_pop(),c2 = S_pop();
			S_push(c2 + ((c1 * 2) > 1 ? (c1 * 2) : 1));
		}
	}
	return S_pop();
}
int main()
{
    char s[50]; scanf("%s",s);
    int num; num = F(s);
    printf("%d",num);
    return 0;
}
