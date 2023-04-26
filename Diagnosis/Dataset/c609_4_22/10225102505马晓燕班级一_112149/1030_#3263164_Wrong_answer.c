#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double table[128]={0};

int cmp(const void*a, const void*b)
{
	char m = *(char*)a , n = *(char*)b;
	if(m == n)
		return 0;
	else if(m == n - 32 || n == m - 32)
		return m < n ? 1 : -1;
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