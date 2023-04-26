#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(int num)
{
    int c = sizeof(num);
    unsigned char *p = (unsigned char *)num;
    while(c--)
    {
        printf("%02x%c",*(p++),c=0 ? '\n':' ');
    }
}

void dd(double num)
{
    int c = sizeof(num);
    unsigned char *p = (unsigned char *)c;
    while(c--)
    {
        printf("%02x%c",*(p++),c=0 ? '\n':' ');
    }
}
int main(void)
{
    char s[100];
    while(scanf("%s",s) != EOF){
        if(strchr(s,'.')){
            dd(atof(s));
        }
        else{
            solve(atoi(s));
        }
    }
    return 0;
}
