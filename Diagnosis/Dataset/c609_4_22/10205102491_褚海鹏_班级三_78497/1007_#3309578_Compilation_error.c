#include <stdlib.h>

struct MyStruct{int n;long long int numbers;};

int cmp(const void *a, const void *b)
{
	struct MyStruct d1, d2;
	d1=*((struct MyStruct*)a);
	d2 = *((struct MyStruct*)b);
	if (d1.n != d2.n)
		return d2.n - d1.n;
	else {
		if (d1.numbers > d2.numbers)return 1;
		else return -1;
	}
}
void solve()
{
	MyStruct data[10000];
	int n;
	scanf("%d",&n);
	for (int i = 0; i <n; i++)
	{
		long long int d = 1;
		data[i].n = 0;
		scanf("%d", &data[i].numbers);
		for (int j = 0; j < 64; j++)
		{
			if (data[i].numbers&d)
				data[i].n++;
			d = d << 1;
		}
	}
	qsort(data, n, sizeof(data[0]), cmp);
	for (int i = 0; i < n-1; i++)
	{
		printf("%d ",data[i].numbers);
	}
	printf("%d",data[n - 1].numbers);
}
int main()
{
	int t;
	scanf("%d",&t);
	for (int i=0;i<t;i++)
	{
		printf("case #%d:",i);
		solve();
	}
	return 0;
}