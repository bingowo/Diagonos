#include<stdio.h>
#include<string.h>
#include<stdlib.h>
double solve()     //递归函数，用来读取字符串 
{
    char s[101];
    scanf("%s",&s); //重点：必须用scanf，这样读到空格自动停止 
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
    scanf("%d",&T);
    int i;
    for(i = 0; i < T; i++)
    {
        printf("case #%d:\n", i);
        printf("%.6lf\n", solve());
    }
    return 0;
}