#include <stdio.h>
#include <stdlib.h>

double cal(void);

int
main()
{
    int questions;
    double res;
    
    scanf("%d",&questions);
    getchar();
    for (int i=0; i<questions; i++)
    {
        res = 0.0;
        res = cal();
        printf("case #%d:\n",i);
        printf("%.6f\n",res);
    }
    return 0;
}

double
cal(void)
{
    char c[11] = {'\0'};
    scanf("%s",c);
    switch (c[0])
    {
        case ('+'):
            return cal()+cal();
            break;
        case ('-'):
            return cal()-cal();
            break;
        case ('*'):
            return cal()*cal();
            break;
        case ('/'):
            return cal()/cal();
            break;
        default:
            return atof(c);
            break;
    }
}
