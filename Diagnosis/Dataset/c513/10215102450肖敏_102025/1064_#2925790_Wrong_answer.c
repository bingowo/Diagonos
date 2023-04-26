#include <stdio.h>
#include <ctype.h>
#include <string.h>
double polish_expr() {
    char a[11];
    double f1, f2;
    scanf("%s", a);
    switch (a[0]) {
        case '+':
            f1 = polish_expr();
            f2 = polish_expr();
            return f1 + f2;
        case '-' :
            f1 = polish_expr();
            f2 = polish_expr();
            return f1 - f2;
        case '*':
            f1 = polish_expr();
            f2 = polish_expr();
            return f1 * f2;
        case '/':
            f1 = polish_expr();
            f2 = polish_expr();
            return f1 / f2;
        default:
            return atof(a);
    }
}
int main(){
    int T;
    for(int i=0;i <T;i++)
    {
        printf("case #%d:\n",i);
        printf(".6lf\n",polish_expr());
    }
    return 0;
}