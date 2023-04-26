#include<stdlib.h>
#include<stdio.h>

int cmp(const void* p1, const void* p2)
{
	int a = *(int*)p1;
	int b = *(int*)p2;
	return a - b;
}

int main()
{
	int myin[10001]={0};
	int myout[10001]={0};
	int T,n,count= 0,temp = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);
		for (int i = temp;i <temp + n;i++)
		{
			scanf("%d", &myin[i]);
			
		}
		temp += n;

	}
	qsort(myin, temp, sizeof(int), cmp);
	
	for (int i = 0; i < temp; i++)
	{ //printf("%d ", myin[i]);
		/*if*/
		myout[myin[i]] += 1;
	}
	for (int i = 0; i < temp; i++)
	{
		if (myout[i] == T)
			printf("%d ", i);
	}

	return 0;
}