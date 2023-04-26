#include <stdio.h>
#include <stdlib.h>

typedef struct{
	long long R;
	long long H;
	long long S1;//侧面积 
	long long S2;//底面积 
} YUAN;

int cmp(const void *a, const void *b)
{
	YUAN *p1 = (YUAN *)a, *p2 = (YUAN *)b;
	if (p1->S1 - p2->S1 > 0) return -1;
	else if (p1->S1 - p2->S1 < 0) return 1;
	else 
	{
		if (p1->S2 - p2->S2 > 0) return -1;
		else return 1;
	}
}

int main()
{
	int n,m;
	scanf ("%d%d",&n,&m);
	YUAN yuan[n];
	for (int i = 0; i < n; i++)
	{
		scanf ("%lld %lld", &yuan[i].R, &yuan[i].H);
		yuan[i].S1 = 2 * yuan[i].R * yuan[i].H;
		yuan[i].S2 = yuan[i].R * yuan[i].R; 
	}
	qsort(yuan, n, sizeof(yuan[0]), cmp);
	long long maxS2 = 0,maxS = 0, maxSS = 0;
	for (int i = 0; i < m; i++)
	{
		maxS += yuan[i].S1;
		if (yuan[i].S2 > maxS2) maxS2 = yuan[i].S2;
	}
	maxS += maxS2;
	int x;
	for (int i = 0; i < n; i++)
	{
		if (yuan[i].S2 > maxS2) maxS2 = yuan[i].S2, x = i;
	}
	int j = 0;
	m--;
	while (m)
	{
		if (j == x)
		{
			j++;
			m--;
			continue;
		} 
		maxSS += yuan[j].S1;
		m--;
		j++;
	}
	maxSS += yuan[x].S1 + yuan[x].S2;
	long long max;
	max = maxS > maxSS ? maxS : maxSS;
	printf("%lld", max);
	return 0;
}