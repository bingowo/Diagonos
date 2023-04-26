#include <stdio.h>
#include <math.h>
double polish_expr() {
    char a[101];
    double f1, f2;
    scanf("%s", a);
    switch (a[0]) {
        case '+':
            return polish_expr()+polish_expr();
        case '-' :
            return polish_expr()-polish_expr();
        case '*':
            return polish_expr()*polish_expr();
        case '/':
            return polish_expr()/polish_expr();
        default:
            return atof(a);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i <T;i++)
    {
        double r;
        r = polish_expr();
        printf("case #%d:\n%.6lf\n",i,r);
    }
    return 0;  
}
