#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
double solve()
{
    char s[12];
    scanf("%s",s);
    switch(s[0])
    {
        case '+':return solve()+solve();
        case '-':return solve()-solve();
        case '*':return solve()*solve();
        case '/':return solve()/solve();
        default :return atof(s);
    }
}
int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        printf("%.6lf\n",solve());
    }
}
