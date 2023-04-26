#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 10001
struct A
{
    long long num;  // 输入的数
    int cnt;  // '1'的个数
};
int getnum(long long a)
{
	long long d = 1; 
	int num = 0,k=0;
	while(k<64)
	{
		if (a & d) num++;
		d = d *2;
        k++;
	}
	return num;
}
int cmp(const void* a, const void* b)
{
    struct A d1, d2;
    d1 = *((struct A*)a);
    d2 = *((struct A*)b);
    if (d2.cnt != d1.cnt)
        return d2.cnt - d1.cnt;
    else
        return d1.num - d2.num;
}
int main()
{
    int T;int N;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        struct A S[MAXN];
        for (int j = 0; j < N; j++)
        {
            scanf("%lld", &S[j].num);
            S[j].cnt = getnum(S[j].num);
        }
        qsort(S, N, sizeof(S[0]), cmp);
        printf("case #%d:\n", i);
        int j;
        for (j = 0; j < N - 1; j++)
            printf("%lld ", S[j].num);
        printf("%lld\n", S[j].num);
    }
    return 0;
}