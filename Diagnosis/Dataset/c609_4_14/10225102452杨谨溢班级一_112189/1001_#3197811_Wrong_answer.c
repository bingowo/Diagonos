#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int T;
    scanf("%lld",&T);
    char C[37] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G',
    'H','I','G','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    while(T--)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        char num[40],rnum[40];
        int j = 0;
        if (n<0)  num[0] = '-',j++,n=0-n;
        int i = 0;
        while(n>0)
        {
            int a = n%r;
            rnum[i++] = C[a];
            n = n/r;
        }
        for (int e = i-1;e>=0;--e)
        {
            num[j++] = rnum[e];
        }
        num[j] = 0;
        printf("%s\n",num);
    }
    return 0;
}
