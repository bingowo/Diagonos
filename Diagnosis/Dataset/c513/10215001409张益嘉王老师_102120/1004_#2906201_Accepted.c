#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solveint(int n)
{
    int c=sizeof(n);
    unsigned char* p=(unsigned char*)&n;
    while(c--)
    {
        printf("%02x ",*p++);
    }
    printf("\n");

}

void solvedouble(double dou)
{
    int c=sizeof(dou);
    unsigned char* p=(unsigned char*)&dou;
    while(c--)
    {
        printf("%02x ",*p++);
    }
    printf("\n");
}

int main()
{
    char s[40];
   while(scanf("%s",s)!=EOF)
   {
       if(strchr(s,'.')==0)
       {
           int n=atoi(s);
           solveint(n);

       }
       else
       {
           double dou=atof(s);
           solvedouble(dou);
       }
   }
   return 0;
}
