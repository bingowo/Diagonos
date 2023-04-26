#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


void solveint(int n)
{
    int c=sizeof(n);
    unsigned char *p=(unsigned char *)&n;
    while (c--) {
        printf("02x",*p++);
    }
}

void solvedouble(double d)
{
    int c=sizeof(d);
    unsigned char *p=(unsigned char *)&d;
    while (c--) {
        printf("02x",*p++);
    }
}

int main()
{
    char s[32];
    while ((scanf("%s",s))!=EOF) {
        if (strstr(s, '.')==0) {
            solveint(atoi(s));
        }
        else{solvedouble(atof(s));
            printf("\n");
        }
    }
    return 0;
}
