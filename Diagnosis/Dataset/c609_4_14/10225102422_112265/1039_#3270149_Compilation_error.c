/*s1可能在右边，s2在左边，有可能s1,s2可能相同,strstr,strrstr(自己写这个函数)*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 80
int index1(const char* s1, const char* s)
{
	char* ret = strstr(s, s1);
	if (ret == NULL)
		return -1;
	else
		return (int)(ret - s);
}
int index2(const char* s2, const char* s)
{
	char* ret = strrstr(s, s2);
	if (ret == NULL)
		return -1;
	else
		return (int)(ret - s);
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
			printf("%d\n", abs(dex2 - dex1));
	}
	return 0;
}