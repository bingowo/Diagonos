#include <stdio.h>
#include <stdlib.h>

void f1(int n)
{
    int len=sizeof(int);
    unsigned char* p=(unsigned char *)&n;
    while(len--){
        printf("%02x ",*p);
        p++;
    }
}

void f2 (double n)
{
    int len=sizeof(double);
    unsigned char* p=(unsigned char *)&n;
    while(len--){
        printf("%02x ",*p);
        p++;
    }
}

int main()
{
    char s[50];
    while (scanf("%s",s)!=EOF){
        if (strchr(s,'.')==0) f1(atoi(s));
        else f2(atof(s));
        printf("\n");
    }
    return 0;
}
