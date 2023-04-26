#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int n;
        scanf("%d",&n);
        int max=1;
        int x=n%2;
        n/=2;
        int cnt=1;
        while(n!=0)
        {
            if(x!=n%2)
            {
                cnt++;
            }
            else
            {
                cnt=1;
            }
            x=n%2;
            n/=2;
            if(cnt>=max) max=cnt;
        }
        printf("case #%d:\n",cas);
        printf("%d\n",max);
    }
    return 0;
}

