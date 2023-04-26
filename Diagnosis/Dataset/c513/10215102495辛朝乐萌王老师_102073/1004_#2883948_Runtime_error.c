#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shoumemory(char a)
{
    int c = sizeof(a);
    unsigned char *p=(unsigned char*)(&a);
    while(c--){
        printf("%02x",*p++);
    }
    printf("\n");
    return;

}

int main()
{
    char s[100];
    while(scanf("%s",s) != EOF)
    {
        if(strstr(s,'.') == 0)
            shoumemory(atoi(s));
        else
            shoumemory(atof(s));
    }
}
