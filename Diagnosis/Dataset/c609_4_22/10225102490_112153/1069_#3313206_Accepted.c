#include <stdio.h>

#define N 32
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF && n != -1)
    {
        unsigned f[N] = {0};
        int i,j; f[m] = 1;
        for (i = m; i < n; i++)
        {
            f[i+1] = 2*f[i] + (1 << (i-m)) - f[i-m];
        }
        printf("%u\n",f[n]);
    }
    return 0;
}

/*
设已经求得n位数中含连续m个1的串的个数为fn，
则f（n+1）=【n+1位0开头的计数】+【n+1位1开头的计数】
          = f（n）+【n+1位1开头的计数】
          = f（n）+ f(n)+【n位“m+1个1 + 1个0”开头的计数】- 【n位中后n-m位满足条件的计数】
          = 2f（n）+【pow（2，n-m）】-【f（n-m）】
          = 2f（n）+（1<<n-m) - f(n-m)
*/