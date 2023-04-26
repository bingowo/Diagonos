#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double solve()
{
    char s[10086];
    scanf("%s\n",s);
    switch(s[0])
    {
    case '+':
        return solve() + solve();
        break;
    case '-':
        return solve() - solve();
        break;
    case '*':
        return solve() * solve();
        break;
    case '/':
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
    scanf("%d\n",&T);
    for(int i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        printf("%.6lf\n", solve());
    }
    return 0;
}