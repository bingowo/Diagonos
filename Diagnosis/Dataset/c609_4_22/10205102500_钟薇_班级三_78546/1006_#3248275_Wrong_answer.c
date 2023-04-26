#include<stdio.h>
#include<stdlib.h>

int main()
{
    char s[62];	
    scanf("%s", &s);

    int a[128], i;
    for (i = 0; i < 128; ++i)   a[i] = -1;

    int N = 0;
    char* p = s;
    a[*p] = 1;

    while (*++p)
        if (a[*p] == -1)	// 之前有的可以屏蔽掉
        {
            a[*p] = N;
            N = N ? N + 1 : 2;
        }
    if (N < 2)
        N = 2;	// 不可能是一进制

    // int digit=0; 
    // while (*++p)
    //     if (a[*p]==-1) 
    //     { 
    //         a[*p]=digit; 
    //         digit=digit?digit+1:2; 
    //         N++;
    //     }

    long long ans = 0;
    p = s;
    while (*p)  ans = ans * N + a[*p++];
    printf("%I64d\n", ans);

    // long long ans=0;
    // p=s; 
    // while (*p) ans=ans*N+a[*p++];
    // printf("%lld\n",ans);

    return 0;
}