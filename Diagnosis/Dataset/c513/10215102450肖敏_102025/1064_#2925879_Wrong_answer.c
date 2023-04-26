#include <stdio.h>
#include <math.h>
double polish_expr() {
    char a[101];
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
    scanf("%d",&T);
    getchar();
    for(int i=0;i <T;i++)
    {
        printf("case #%d:\n%.6lf\n",i,polish_expr());
    }
    return 0;
}