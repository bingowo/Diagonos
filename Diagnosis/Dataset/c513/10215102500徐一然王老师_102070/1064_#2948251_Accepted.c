#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double polish()
{
    char a[10];
    double f1,f2;
    scanf("%s",a);
    {
        switch(a[0])
        {
        case '+':{f1=polish();f2=polish();return f1+f2;}
        case '-':{f1=polish();f2=polish();return f1-f2;}
        case '*':{f1=polish();f2=polish();return f1*f2;}
        case '/':{f1=polish();f2=polish();return f1/f2;}
            default:return atof(a);
        }
    }
}

int main()
{
    int count,count1;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {

        printf("case #%d:\n",count1-count-1);
        printf("%lf\n",polish());
    }
}
