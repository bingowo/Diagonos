#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double boole()
{
    char s[100];
    scanf("%s",s);
    switch (s[0])
    {
    case '+':return boole() +boole();
    case '-':return boole() -boole();
    case '*':return boole() *boole();
    case '/':return boole() /boole();
    default:return atof(s);
    }

}
int main()
{
    int t;
    scanf("%d",&t);
    int i =0;
    for(;i< t;i++)
    {
        double p =boole();
        printf("case #%d:\n",i);
        printf("%.6f",p);
        if(i<t-1)printf("\n");
    }
    return 0;
}
