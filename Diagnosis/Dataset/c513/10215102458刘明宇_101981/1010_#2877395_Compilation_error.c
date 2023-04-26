#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    char *s1;
    char s;
    gets(s);
    s1 = s;
    int len = strlen(s);
    int cps;
    int cpl[200][3];

    if(len % 3 == 0) cps = len/3;
    if(len % 3 != 0) cps = len/3 + 1;
    for(int i = 0;i < cps;i++)
        for(int j = 0;j < 3;j++)
            cpl[]

    printf("%d", s[0]);
    return 0;
}
