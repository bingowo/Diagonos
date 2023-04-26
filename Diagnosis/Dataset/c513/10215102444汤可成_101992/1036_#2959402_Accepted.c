#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point
{
    long long x;
    long long y;
    unsigned long long xy;
};

int cmp(const void* pa, const void* pb)
{
    struct point* a = (struct point*)pa;
    struct point* b = (struct point*)pb;
    if(a->xy > b->xy) return -1;
    else if(a->xy < b->xy) return 1;
    else
    {
        if(a->x < b->x) return -1;
        else if(a->x > b->x) return 1;
        else
        {
            if(a->y < b->y) return -1;
            else return 1;
        }
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    struct point a[101];
    for(int i = 0; i<n; i++)
    {
        scanf("%lld %lld", &a[i].x, &a[i].y);
        a[i].xy = llabs(a[i].x) + llabs(a[i].y);
    }
    qsort(a, n, sizeof(a[0]), cmp);
    unsigned long long p,q;
    unsigned long long n1 = llabs(a[0].x - a[1].x);
    unsigned long long n2 = llabs(a[0].y - a[1].y);
    if(n1+n2!=0)printf("%llu\n", n1+n2);
    else if(n1+n2==0 && n1>0) printf("18446744073709551616\n");
    else printf("0\n");
    int fp = 0;
    for(int i = 0; i<n-1; i++)
    {
        p = llabs(a[1+i].x - a[0+i].x);
        q = llabs(a[i+1].y - a[0+i].y);
        if((p%2 == 0 && q%2 != 0) || (p%2 != 0 && q%2==0) || (p == 0 && q == 0))
        {
            while(p != 0 || q != 0)
            {
                fp++;
                if(p%2 != 0)
                {
                    q = q/2;
                    if(q%2 == 0)
                    {
                        if( q == 0 && p == 1)
                        {
                            p = 0;
                        }
                        else
                        {
                            if(((p+1)/2)%2 != 0) p = (p+1)/2;
                            else p = (p-1)/2;
                        }

                    }
                    else
                    {
                        if(((p+1)/2)%2 == 0) p = (p+1)/2;
                        else p = (p-1)/2;
                    }
                }
                else
                {
                    p = p/2;
                    if(p%2 == 0)
                    {
                        if(p == 0 &&  q==1)
                        {
                            q = 0;
                        }
                        else
                        {
                            if(((q+1)/2)%2 != 0) q = (q+1)/2;
                            else q = (q-1)/2;
                        }
                    }
                    else
                    {
                        if(((q+1)/2)%2 == 0) q = (q+1)/2;
                        else q = (q-1)/2;
                    }
                }
            }
        }
        else break;

    }
    printf("%d", fp);
    return 0;
}
