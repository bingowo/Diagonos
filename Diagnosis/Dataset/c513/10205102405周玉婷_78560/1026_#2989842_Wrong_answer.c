#include <stdio.h>
#include <stdlib.h>
/*换言之，是将读入的数据排序，然后每两个相邻的数据求距离。
1.输入数据2.排序3.计算4.输出*/
typedef long long int lli;
int cmp (const void *a,const void *b)
{
	lli* pa = (lli*) a;
	lli* pb = (lli*) b;
	return (*pa)<(*pb)?-1:1;
}
int main()
{
	int n;
	scanf ("%d", &n);
	lli dis;
	lli* p = (lli*)malloc(sizeof(lli)*n);
	for(int i=0; i<n; i++)
	{
		scanf("%lld",&p[i]);
	}
	
	qsort(p,n,sizeof(lli),cmp);
	for (int i=0; i<n; i+=2)
	{
		dis+=(p[i+1] - p[i]);
	}
	printf("%lld\n",dis);
	return 0;
}