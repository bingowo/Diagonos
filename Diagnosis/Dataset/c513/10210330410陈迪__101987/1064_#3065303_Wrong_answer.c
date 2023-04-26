#include <stdio.h>
#include <stdlib.h>

double solve()
{
    char s[10086];
    scanf("%s",s);
    switch(s[0])
    {
    case '+':
        return solve() + solve();
        break;
    case '-':
        return solve() - solve();
        break;
    case '*':
        return solve() / solve();
        break;
    default:
        return atof(s);
        break;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        printf("%.61f\n", solve());
    }
    return 0;
}
