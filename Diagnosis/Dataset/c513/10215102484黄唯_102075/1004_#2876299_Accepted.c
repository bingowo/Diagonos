//2022.2.24

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void myint(int n)
{
   int c=sizeof(n);
   unsigned char *p=(unsigned char*)&n;
   while(c--)
    printf("%02x ",*p++);
   printf("\n");


}
void mydouble(double d)
{
    int b=sizeof(d);
    unsigned char *p=(unsigned char*)&d;
   while(b--)
    printf("%02x ",*p++);
   printf("\n");
}


int main()
{
    char s[31];
    while(scanf("%s",s)!=EOF)
        if(strchr(s,'.'))
        mydouble(atof(s));
        else myint(atoi(s));

    return 0;
}
