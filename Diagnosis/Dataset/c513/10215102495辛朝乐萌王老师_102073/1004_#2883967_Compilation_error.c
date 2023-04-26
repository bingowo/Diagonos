#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

template<typename T>

void shoumemory(T a)
{
    int c = sizeof(T a);
    unsigned char *p=(unsigned char*)(&a);
    while(c--){
        printf("%02x",*p++);
    }
   cout << endl;
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