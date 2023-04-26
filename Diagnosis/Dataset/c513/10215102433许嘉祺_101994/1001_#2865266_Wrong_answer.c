#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,r;
    char s[33];
    scanf("%d",&t);
    for (int i=0;i<t;i++)
    {
        scanf("%d%d",&n,&r);
        if (n<0) {n=-n;printf("-");}
        int b=1,c=0;
        while (b<=n) {b*=r;c++;}
        s[c]=0;
        while (n>0)
        {
            int a;
            a=n%r;
            n=n/r;
            c=c-1;
            if (a>9) s[c]='A'+a-10;
            else s[c]='0'+a;
        }
        printf("%s\n",s);
    }
    return 0;
}

