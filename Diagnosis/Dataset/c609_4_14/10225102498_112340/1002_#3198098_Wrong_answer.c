#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,n,i,k;
    int p;
    scanf("%d",&T);
    int s[1000];
    for(i=0; i<T; i++)
    {
        int j = 0, k = 0, m = 0;
        scanf("%d",&n);
        while(n>0)
        {
            s[k] = n%2;
            n /= 2;
            k++;
        }
        k--;
        for(p=k; p>=0; p--)
        {
            if(s[p] != s[p+1])
                j++;
            else
            {
                if(j>m)
                    m = j;
                j = 0;
            }
        }
        printf("case #%d:\n%d\n",i,m);
    }
    return 0;
}
