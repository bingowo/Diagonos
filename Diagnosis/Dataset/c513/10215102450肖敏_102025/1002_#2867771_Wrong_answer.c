#include <stdio.h>

int main()
{
    int i,k,e,T,t,j;
    long long int m = 0;
    char s[60];
    char s2[123];

    scanf("%d",&T);

    for(e = 0;e < T;e ++)
    {
        j = 2;
        for(t = 0;t < 123;t ++)
        {
            s2[t] = -1;
        }
        scanf("%s",s);
        for(i= 0;s[i] != '\0';i ++)
        {
            if( s2[s[i]] == -1)
            {
                if(i == 0)
                {
                    s2[s[i]] = 1;
                }
                else if(i == 1)
                {
                    s2[s[i]] = 0;
                }
                else
                {
                    s2[s[i]] = j;
                    j ++;
                }
            }
        }
        for(k = 0;k < i;k ++)
        {
            m = m * j + s2[s[k]];
        }
        printf("case #%d:\n%lld\n",e,m);
    }
    return 0;
}
