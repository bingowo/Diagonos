#include <stdio.h>
#include <stdlib.h>

double polish()
{
    char a[11];
    double f1, f2;
    scanf("%s", a);
    switch(a[0])
    {
        case '+': f1=polish();f2=polish();return f1+f2;
        case '-': f1=polish();f2=polish();return f1-f2;
        case '*': f1=polish();f2=polish();return f1*f2;
        case '/': f1=polish();f2=polish();return f1/f2;
        default: return atof(a);
    }
}

int main()
{
    int i, T;
    scanf("%d", &T);
    for(i=0; i<T; i++)
        printf("case #%d:\n%f\n", i, polish());

    return 0;
}
