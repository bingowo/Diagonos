#include <stdio.h>
#include<string.h>
#define LL long long int
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        char s[61];
        int a[128];
        scanf("%s", s);
        memset(a, -1, sizeof(int) * 128);
        int R = 0;
        char *p = s;
        a[*p] = 1;//第一位不能是0
        while(*++p)
        {
            if(a[*p] == -1)
            {
                a[*p] = R;
                R = R ? R+1 : 2;
            }
        }
        if(R < 2) R = 2;
        LL N = 0;
        p = s;
        while(*p) N = N * R + a[*p++];
        printf("case #%d:\n%lld\n", i, N);
    }
    return 0;
}
