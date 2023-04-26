#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int z=0; z<T; z++)
    {
        int cnt=0;
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            while(i%5==0)
            {
                cnt++;
                i/=5;
            }
        }
        printf("case #%d:\n",z);
        printf("%d\n",cnt);
    }
}
