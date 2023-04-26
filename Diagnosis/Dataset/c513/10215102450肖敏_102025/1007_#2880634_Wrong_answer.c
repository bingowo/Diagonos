#include <stdio.h>

int main()
{
    int T,i,n,c,j,max,k;
    int s[16];
    scanf("%d",&T);
    for(i = 0;i < T;i ++)
    {
        c =1,j = 0,max = 0;
        scanf("%d",&n);
        while(n != 0)
        {
            s[j++] = n % 2;
            n /= 2;
        }
        for(k = j - 1;k > 0;k --)
        {
            if(s[k] != s[k-1])
                c ++;
            else
            {
                max= (max > c) ?max:c;
                c =1;
            }
        }
        printf("case #%d:\n%d\n",i,max);
    }

    return 0;
}
