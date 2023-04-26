#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n=0,T;
    scanf("%d\n",&T);
    for (;n<T;n++)
    {
        char s[20];
        int i=0;
        long long int rs=0;
        s[i]=getchar();
        while (s[i] != '\n')
        {
            if (s[i]=='1') rs=rs*3+1;
            if (s[i]=='0') rs=rs*3;
            if (s[i]=='-') rs=rs*3-1;
            s[++i]=getchar();
        }
        printf("case #%d:\n",n);
        printf("%lld\n",rs);
    }
    return 0;
}
