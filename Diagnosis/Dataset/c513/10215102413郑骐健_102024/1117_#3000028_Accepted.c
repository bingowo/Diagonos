#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>
void cal(long long int* p, long long int* p1, long long int list[][2],long long int *min,int*num)
{
	long long int min_;
	min_ = (fabs(p[0] - p1[0]) < fabs(p[1] - p1[1]) )? fabs(p[1] - p1[1]):fabs(p[0] - p1[0]);
	if (min_ < *min)
	{
		*min = min_;
		list[0][0] = p1[0];
		list[0][1] = p1[1];
		*num = 1;
	}
	else if (min_ == *min)
	{
		list[*num][0] = p1[0];
		list[*num][1] = p1[1];
		*num += 1;
	}
}
int sort(long long int list[][2],int num)
{
	int min = 0;
	for (int i = 0;i < num;i += 1)
	{
		if (list[i][0] < list[min][0])
		{
			min = i;
		}
		else if (list[i][0] == list[min][0] && list[i][1] <= list[min][1])
		{
			min = i;
		}
	}
	return min;
}
int main()
{
	int num;
	int coor_num;
	long long int list[60][2];
	long long int f[2];
	scanf("%lld%lld", &f[0], &f[1]);
	long long int coor[2];
	long long int min =10e15 ;
	scanf("%d", &num);
	for (int i = 0;i < num;i++)
	{
		scanf("%lld%lld", &coor[0], &coor[1]);
		cal(f, coor, list, &min, &coor_num);
	}
	printf("%lld\n", min);
	if (coor_num == 1)
	{
		printf("%lld %lld", list[0][0], list[0][1]);
	}
	else
	{
		int m = sort(list, coor_num);
		printf("%lld %lld", list[m][0], list[m][1]);

	}
	return 0;
}