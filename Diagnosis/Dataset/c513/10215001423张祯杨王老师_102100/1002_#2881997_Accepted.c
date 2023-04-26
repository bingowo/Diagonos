#include <stdio.h>
int main()
{
    int t , i;
    scanf("%d",&t);
    for(int j = 0; j < t; j++)
    {
        char s[60];
        int tmp = 0 , n =1;
        long long ans = 0;
        scanf("%s",s);
        int a[128];
        for(i = 0; i<128; i++)  a[i] = -1;
        char *p = s;
        a[*p] = 1;
        while(*++p)
        {
            if(a[*p] == -1)
            {
                a[*p] = tmp;
                if(tmp == 0)    tmp = 2;
                else tmp++;
                n++;
            }
        }
        if(n < 2)   n = 2;
        p = s;
        while(*p)   ans = ans * n + a[*p++];
        printf("case #%d:\n", j);
        printf("%lld\n",ans);
    }



}
