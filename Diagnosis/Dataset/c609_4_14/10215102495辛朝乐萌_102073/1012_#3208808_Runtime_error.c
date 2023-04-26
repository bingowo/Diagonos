#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void change(char s[])
{
    int t=1/8;
    double m=0;
    for (int i = 2; i < strlen(s); ++i) {
         m += atoi(s[i])*t;
         t/=8;
    }
    printf("%f",m);
}


int main()
{
    int t;
    scanf("%d",&t);
    char s[10000];
    for (int i = 0; i < t; ++i) {
        scanf("%s",s);
        printf("case #%d:\n",i);
        change(s);

    }

    return 0;
}