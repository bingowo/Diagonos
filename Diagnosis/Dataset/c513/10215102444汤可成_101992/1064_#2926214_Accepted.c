#include <stdio.h>
#include <stdlib.h>

double polish_expr()
{
    char s[11] = {0};
    scanf("%s", s);
    if(s[0] == '+') return polish_expr() + polish_expr();
    else if(s[0] == '-') return polish_expr() - polish_expr();
    else if(s[0] == '*') return polish_expr() * polish_expr();
    else if(s[0] == '/') return polish_expr() / polish_expr();
    else return atof(s);
}

int main()
{
    int T = 0;
    int i = 0;
    scanf("%d",&T);
    for(i = 0; i<T; i++)
    {
        printf("case #%d:\n", i);
        printf("%.6f\n", polish_expr());
    }
    return 0;
}
