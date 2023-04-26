#include <stdio.h>
#include <stdlib.h>
/*换言之，是将读入的数据排序，然后每两个相邻的数据求距离。
1.输入数据2.排序3.计算4.输出*/
/*犯的错误：
1.把数据类型定义为int,但距离定义为long long ，在转换的过程中会出现错误，所以要统一数据
观察数据可知，dis不会超过int，所以节省空间定义为Int
2.qsort的第一个参数是储存空间的指针，故不用数组名只用指针即可
3.malloc与qsort都在stdlib头文件里*/
int cmp (const void *a,const void *b)
{
	int pa = *(int*) a;
	int pb = *(int*) b;
	return pa>pb?1:-1;
}
int main()
{
	int n;
	scanf ("%d", &n);
	int dis=0;int* p = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
	{
		scanf("%d",&p[i]);
	}
	
	qsort(p,n,sizeof(int),cmp);
	for (int i=0; i<n; i+=2)
	{
		dis+=(p[i+1] - p[i]);
	}
	printf("%d\n",dis);
	return 0;
}