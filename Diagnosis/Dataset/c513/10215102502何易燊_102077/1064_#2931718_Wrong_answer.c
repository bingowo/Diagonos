#include <stdio.h>
#include <stdlib.h>

double deal()
{
    char s[11] = {}; scanf("%s",s);
    double l,r;
    switch (s[0])
    {
        case '+': l = deal(); r = deal(); return l+r;
        case '-': l = deal(); r = deal(); return l-r;
        case '*': l = deal(); r = deal(); return l*r;
        case '/': l = deal(); r = deal(); return l/r;
        default: return atof(s);
    }
}

int main()
{
    int T; scanf("%d ",&T);
    for (int i=0;i<T;i++)
    {
        double ans;
        ans = deal();
        printf("case #%d\n:%lf\n",i,ans);
    }
    return 0;
}