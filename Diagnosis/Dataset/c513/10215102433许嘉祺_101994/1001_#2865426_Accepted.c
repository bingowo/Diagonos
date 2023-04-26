#include <stdio.h>
#include <stdlib.h>

int main()
{int t;
    int r;
    int n;
    char s[33];
    scanf("%d",&t);
    for (int i=0;i<t;i++)
    {
        scanf("%d%d",&n,&r);
        int c=0;
        if (n<0) {n=-n;printf("-");}
        while (n>0)
        {
            int a;
            a=n%r;
            n=n/r;
            if (a>9) s[c++]='A'+a-10;
            else s[c++]='0'+a;
        }
        for (int i=c-1;i>=0;i--)
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
