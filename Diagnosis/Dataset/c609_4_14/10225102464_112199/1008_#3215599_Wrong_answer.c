#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sint (int a)
{
    int t=sizeof(int);
    unsigned char* p=(unsigned char*)&a;
    while(t--)
    {
        printf("%02x ",*p++);
    }
    printf("\n");
}
void sdouble(double b)
{
    int t=sizeof(double);
    unsigned char*p=(unsigned char *)&b;
    while(t--)
    {
        printf("%02x ",*p++);
    }
    printf("\n");
}

int main()
{
   char s[100];
   while(scanf("%s",s)!=EOF)
   {
       if(strchr(s,'.'==0))
          sint(atoi(s));
       else
        sdouble(atof(s));
   }
    return 0;
}