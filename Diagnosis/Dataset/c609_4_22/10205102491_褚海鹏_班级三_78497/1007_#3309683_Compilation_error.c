#include <stdlib.h>

struct data
{
    long long int a; 
    int number; 
};

int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if(d2.number!=d1.number)
    return d2.number-d1.number;
    else
    { 
        if(d1.a>d2.a) return 1;
        else return -1;
    }
}
void solve()
{
    struct data p[10000];
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   scanf("%lld",&p[i].a);
        d=1;p[i].number=0;
        for(t=0;t<64;t++)   
        {
            if(p[i].a&d) p[i].number++;
            d=d<<1;
        }
    }
	qsort(p, n, sizeof(p[0]), cmp);
    for(i=0;i<n-1;i++)
        printf("%lld ",p[i].a);
    printf("%lld\n",p[i].a);
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