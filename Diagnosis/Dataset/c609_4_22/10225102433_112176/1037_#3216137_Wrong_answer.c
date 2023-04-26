//-std=c99
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000001

char s[N];
int main()
{
	int begin = 0;
	int end = 0;
	int a[128] = {0};
	scanf("%s",s);
	unsigned len = strlen(s);
	if(len == 1)
	{
		printf("%s",s);
		return 0;
	}
	for(int i = 0;i < len;i++)
	{
		if(a[s[i]] == 0)
		{
			a[s[i]]++;
		}
		else
		{
			end = i-1;
			break;
		}
	}
	if(end == 0)
	{
		end = len-1;
	}
//	printf("%d %d",begin,end);
	int length = end-begin;
	int r1 = 0,r2 = end+1;
	a[s[r1]] = 0;
	for(;r2 < len;r2++)
	{
		while(a[s[r2]] != 0)
		{
			a[s[r1]] = 0;
			r1++;
		}
		printf("%d %d\n",r1,r2);
		a[s[r2]]++;
		if((r2-r1) > length)
		{
			length = r2-r1;
			begin = r1;
			end = r2;
		}
	} 
	for(int i = begin;i <= end;i++)
	{
		printf("%c",s[i]);
	}
	return 0;
} 