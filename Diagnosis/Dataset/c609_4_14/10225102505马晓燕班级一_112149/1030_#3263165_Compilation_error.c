#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double table[128]={0};

int cmp(const void*a, const void*b)
{
	char m = *(char*)a , n = *(char*)b;
	char m = *(char*)a , n = *(char*)b;
	int x,y;
	if(m >= 'a') x = x -'a'; else x = x - 'A';
	if(n >= 'a') y = y -'a'; else y = y - 'A';
	if(table[m] == table[n])//同频率
	{
		if(m == n)//同字母
			return 0;
		else if(x == y)//大小写不同
			return n - m;
		else
			return y - x;
	}
	else
		return table[n] > table[m] ? 1 : -1;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		double x;
		for(int i='A';i<='Z';i++)
		{
			scanf("%lf",&x);
			table[i] = x;			//大写
			table[i+32] = x;		//小写
		}
		char str[100]={0};
		scanf("%s",str);
		int len = strlen(str);
		qsort(str,len,sizeof(char),cmp);
		
		printf("case #%d:\n",i);
		printf("%s\n",str);
	}
	return 0;
}