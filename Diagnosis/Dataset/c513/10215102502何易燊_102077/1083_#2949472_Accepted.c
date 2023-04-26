#include <stdio.h>

int main()
{
    int T; scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int n; scanf("%d",&n);
        int cnt = 0;
        for (int j=5;j<=n;j+=5)
        {
            int k = j;
            while (k%5==0) {cnt++; k /= 5;}
        }
        printf("case #%d:\n%d\n",i,cnt);
    }
    return 0;
}