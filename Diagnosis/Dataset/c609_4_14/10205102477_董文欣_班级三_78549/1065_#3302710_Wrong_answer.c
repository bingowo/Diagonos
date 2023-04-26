#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double solve(){
    char s[10];
    double f1, f2;
    scanf("%s", s);
    switch (s[0]) {
        case '+' : {f1 = solve(); f2 = solve(); return f1 + f2;}
        case '-' : {f1 = solve(); f2 = solve(); return f1 - f2;}
        case '*' : {f1 = solve(); f2 = solve(); return f1 * f2;}
        case '/' : {f1 = solve(); f2 = solve(); return f1 / f2;}
        default : {return atof(s);}
    }
}

int main()
{
    int T;
    scanf ("%d\n", &T);
    for (int cas = 0; cas < T; cas++) {
        printf("case #%d\n%.6f\n", cas, solve());
    }
    return 0;
}
