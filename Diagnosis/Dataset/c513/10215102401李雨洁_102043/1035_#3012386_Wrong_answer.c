#include <stdio.h>
#include <stdlib.h>

struct node
{
	long long r,h,s;
};

int cmp(const void *_x,const void *_y)
{
    struct node x,y;
    x = *((struct node *)_x);
    y = *((struct node *)_y);
    return x.s > y.s;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	struct node a[1001];
	for (int i = 1; i <= n; i++)
	{
	    scanf("%lld %lld",&a[i].r,&a[i].h);
		a[i].s = 2 * a[i].r * a[i].h;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	long long res = 0;
	for(int i = 1; i <= n; i++)
	{
		long long sum = a[i].s + a[i].r*a[i].r;
		int count = 1;
		for(int j = 1; j <= n && count < m; j++)
		{
			if(i == j || a[j].r > a[i].r)
                continue;
			sum += a[j].s;
			count++;
		}
		if(count == m)
        {
            if(sum > res) res = sum;
        }
	}
	printf("%lld\n",res);
	return 0;
}

