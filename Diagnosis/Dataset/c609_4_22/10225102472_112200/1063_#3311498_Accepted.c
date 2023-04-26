#include<stdio.h>
#include<string.h>

int main()
{
    int T, n;
    scanf("%d", &T);
    for(int k = 0; k < T; k++)
    {
        int n;
        scanf("%d", &n);
        long long v[n+5];
        v[0] = 1, v[1] = 1, v[2] = 2, v[3] = 4;
        for(int i = 4; i < n+1; i++)
        {
            v[i] = v[i-1] + v[i-2] + v[i-3] + v[i-4];
        }
        printf("case #%d:\n", k);
        printf("%lld\n", v[n]);
    }

    return 0;
}