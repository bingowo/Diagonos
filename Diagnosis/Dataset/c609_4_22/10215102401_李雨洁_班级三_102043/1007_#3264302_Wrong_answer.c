#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000
struct my_sort
{
    long long num;  // 输入的数
    int cnt;  // '1'的个数
};

int cmp(const void* a, const void* b)
{
    struct my_sort d1,d2;
    d1=*((struct my_sort *)a);
    d2=*((struct my_sort *)b);
    if(d2.cnt!=d1.cnt) return d2.cnt-d1.cnt;
    else
        return d1.num-d2.num;
}
int getnum(long long a)
{
	long long d = 1,k=0;
    int num = 0;
	while(k<64)
	{
		if (a & d) num++;
		d = d *2;
        k++;
	}
	return num;
}
int main()
{
    int T; 
    scanf("%d",&T);
    for(int i = 0; i < T; ++i)
    {
        int N; 
        scanf("%d",&N);
        struct my_sort S[MAXN];
        for(int j = 0; j < N; ++j)
        {
            scanf("%lld",&S[j].num);
            S[j].cnt = getnum(S[j].num);
        }
        qsort(S, N, sizeof(S[0]),cmp);
        printf("case #%d:\n",i);
        int j;
        for(j = 0; j < N - 1; j++)
            printf("%lld ",S[j].num);
        printf("%lld\n",S[j].num);
    }
    return 0;
}