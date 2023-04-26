#include <stdio.h>
#include <stdlib.h>
/*换言之，是将读入的数据排序，然后每两个相邻的数据求距离。
1.输入数据2.排序3.计算4.输出*/
int cmp (const void *a,const void *b)
{
	int* pa = (int*) a;
	int* pb = (int*) b;
	return *pa<*pb?-1:1;
}
int main()
{
	int n;
	scanf ("%d", &n);
	long long int dis;
	int* p = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&p[i]);
	}
	
	qsort(p,n,sizeof(int),cmp);
	for (int i=0; i<n; i+=2)
	{
		dis+=(p[i+1] - p[i]);
	}
	printf("%lld\n",dis);
	return 0;
}