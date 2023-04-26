#include <stdio.h>
#include <stdlib.h>

typedef struct{
	long long x;
	long long y;
	unsigned long long distance;
} POINT;

int cmp(const void *a, const void *b)
{
	POINT *p1 = (POINT *)a, *p2 = (POINT *)b;
	if (p1->distance - p2->distance > 0) return -1;
	else if (p1->distance - p2->distance < 0) return 1;
	else
	{
		if (p1->x - p2->x > 0) return 1;
		else if (p1->x - p2->x < 0) return -1;
		else
		{
			if (p1->y - p2->y > 0) return 1;
			else return -1;
		}
	}
}

int main()
{
	int n;
	scanf ("%d", &n);
	POINT point[n];
	for (int i = 0; i < n; i++)
	{
		scanf ("%lld%lld", &point[i].x, &point[i].y);
		long long X = point[i].x >= 0 ? point[i].x : -point[i].x, Y = point[i].y >= 0 ? point[i].y : -point[i].y;
		point[i].distance = X + Y; 
	}
	qsort (point, n, sizeof(point[0]),cmp);
	int step = 0, dist = 1;
	unsigned long long distance1, distancei;
	for (int i = 1; i < n; i++)
	{
		long long disX = point[i].x - point[i-1].x >= 0 ? point[i].x - point[i-1].x : point[i-1].x - point[i].x, disY = point[i].y - point[i-1].y >= 0 ? point[i].y - point[i-1].y : point[i-1].y - point[i].y;
		if (i == 1) distance1 = disX + disY;
		distancei = disX + disY;
		if (distancei % 2 == 1)
		{
			while(distancei) step++, distancei/=2;
		}
		else if (distancei == 0) continue;
		else break;
	}
	printf ("%llu\n%lld", distance1, step);
	return 0; 
}