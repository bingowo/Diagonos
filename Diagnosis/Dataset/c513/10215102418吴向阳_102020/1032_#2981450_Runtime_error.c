#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
	int *p = (int *)a,*q = (int *)b;
	if(p[0] - q[0] > 0) return -1;
	else if (p[0] - q[0]< 0) return 1;
	else
	{
		int i = 1,j = 1;
		while(1)
		{
			if(p[i] == -1) return 1;
			else if(q[i] == -1) return -1; 
			if(p[i] - q[j] > 0) return -1;
			else if (p[i] - q[j]< 0) return 1;
			i++,j++;
		}
	}
}

int main()
{
	int T,t;
	scanf("%d",&T);
	t = T;
	while(T)
	{
		int N;
		scanf("%d",&N);
		int a[N][50];
		for(int i = 0; i < N; i++)
		{
			int j = 0;
			while(scanf("%d",&a[i][j]))
			{
				if(a[i][j++] == -1) break;
			}
		}
		qsort(a,N,sizeof(a[0]),cmp);
		for (int i = 0; i < N; i++)
		{
			int j = 0;
			while(a[i][j] != -1) printf("%d ",a[i][j++]);
			printf("\n");
		}
		T--;
	}
} 