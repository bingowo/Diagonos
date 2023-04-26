#include <stdio.h>
#include <stdlib.h>

struct  //¶¨Òå£¬¸³Öµ
{
    long long int a;
    int number;
}stu1,stu2;

int cmp(const void *a, const void *b)
{
    struct stu1,stu2;
    stu1=*((struct *)a);
    stu2=*((struct *)b);

    if(stu2.number - stu1.number)
        return stu2.number-stu1.number;
    else
    {
        if(stu1.a > stu2.a)
            return 1;
        else return -1;
    }
}
void Solve()
{
    int N;
    struct p[10000];
    scanf("%d", &N);
    for (int i=0; i<N, i++)
    {
        scanf("%lld", &p[i].a);
        long long mask=1;
        p[i].number=0;
        for(int t=0; t<64;t++)
        {
            if（p[i].a &mask) p[i].number++;
            mask=mask << 1;
        }
    }
    qsort(p, N, sizeof(p[0]), cmp);
    for(int i=0; i < N; i++)
        printf("%lld%c", p[i].a, (i==N-1?'\n':''));
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=0; cas < T; cas++)
    {
        printf("cas #%d:\n", cas);
        Solve();
    }
    return 0;
}
