#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
double polish_exper()
{
    char a[11];
    scanf("%s",a);
    double f1,f2;
    switch(a[0])
    {
    case '+':
        f1=polish_exper();
        f2=polish_exper();
        return f1+f2;
    case'-':
        f1=polish_exper();
        f2=polish_exper();
        return f1-f2;
    case'/':
        f1=polish_exper();
        f2=polish_exper();
        return (f1)/(f2);
    case'*':
        f1=polish_exper();
        f2=polish_exper();
        return f1*f2;
    default:
        return atof(a);
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        double ret =polish_exper();
        printf("case #%d\n",i);
        printf("%.6lf\n",ret);
    }


}
