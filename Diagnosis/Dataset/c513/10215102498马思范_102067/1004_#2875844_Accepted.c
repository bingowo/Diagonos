#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void zheng(int a)
 {
    int b = sizeof(a);
    unsigned char* p = (unsigned char*)&a;
    while (b--)
        printf("%02x ", *p++);
    printf("\n");
}
void dou(double a)
{
    int b = sizeof(a);
    unsigned char* p = (unsigned char*)&a;
    while (b--)
        printf("%02x ", *p++);
    printf("\n");
}

int main()
{
   char s[40];
   int m=0;
   while((scanf("%s",s))!=EOF)
    {
        if(strchr(s,'.')==0)
            zheng(atoi(s));
        else
            dou(atof(s));
    }
   return 0;
}