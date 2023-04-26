#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
double solve()
{   char I[101];scanf("%s", I);
    if (isdigit(*I)) return atof(I);
    double a = solve(), b = solve();
    return *I=='+'?a+b:*I=='-'?a-b:*I=='*'?a*b:a/b;
}
int main()
{   int T, cas = 0;scanf("%d", &T);
    while(T--) printf("case #%d:\n%lf\n", cas++, solve());
    return 0;
}