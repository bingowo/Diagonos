#include <stdio.h>
#include <math.h>
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
    scanf("%d",&T);
    getchar();
    double p;
    for(int i=0;i <T;i++)
    {
        p = polish_expr();
        printf("case #%d:\n",i);
        printf("%.6lf\n",p);
    }
    return 0;
}