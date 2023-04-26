/*s1可能在右边，s2在左边，有可能s1,s2可能相同,strstr,strrstr(自己写这个函数)*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 80
int index1(char* s1, char* s)
{
	int i,j; int flag = 1;
	for (i = 0; i < strlen(s); i++)
	{
		for (j = 0; j < strlen(s1);)
		{
			if (s[i] == s1[j])
			{
				i++;
				j++;
			}
			else
				break;
		}
		if (j == strlen(s1))
		{
			flag = 0;
			break;
		}
	}
	if (flag == 0)
		return i;
	return -1;
}
int index2(char* s2, char* s)
{
	int i = 0,j=0;
	int flag = 1;
	for (i = strlen(s) - 1; i >= 0; i--)
	{
		for (j = strlen(s2) - 1; j >= 0;)
		{
			if (s[i] == s2[j])
			{
				i--;
				j--;
			}
			else break;
		}
		if (j == 0)
		{
			flag = 0;
			break;
		}
	}
	if (flag==0)
		return i;
	return -1;
}
int main()
{
	int T;
	scanf("%d", &T);
	char s[N + 1];
	char s1[N + 1];
	char s2[N + 1];
	for (int i; i < T; i++)
	{
		scanf("%s", s1);
		scanf("%s", s2);
		scanf("%s", s);
		int dex1 = index1(s1, s);
		int dex2 = index2(s2, s);
		printf("case #%d:", i);
		if (dex1 == -1 || dex2 == -1)
			printf("%d\n", 0);
		else
			printf("%d\n", dex2 - dex1);
	}
	return 0;
}