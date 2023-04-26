#include<stdio.h>
#include<string.h>
int c[26];
char b[27];
int p[1000][51];
void memset(int *);
int cmp(const void *a, const void *b)
{
	int  *m, *n;
	m = (int *)a;
	n = (int  *)b;
	while(*m!=-1&&*n!=-1&&*m==*n)
        {*m++;*n++;}
        return *n-*m;
}
void solve()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int c;
		int j = 0;
		scanf("%d", &c);
		while (c != -1)
		{
			p[i][j++] = c;
			scanf("%d", &c);
		}
	}//读取字符串
	qsort(p, n, sizeof(p[0]), cmp);
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (p[i][j+1]!=-1)
		{
			printf("%d ", p[i][j++]);
		}
		printf("%d\n", p[i][j]);
	}
}
int main() {
	int t;
	scanf("%d",&t);
	for (int i = 0; i < t; i++)
	{
		memset(p, -1, sizeof(p));
		solve();
	}
}