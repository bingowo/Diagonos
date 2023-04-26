#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void fint(int s)
{
    int c=sizeof(s);
    unsigned char*p=(unsigned char*)&s;
    while(c--)printf("%02x ",*p++);
    printf("\n");
}
void fdouble(double s)
{
    int c=sizeof(s);
    unsigned char*p=(unsigned char*)&s;
    while(c--)printf("%02x ",*p++);
    printf("\n");
}
int main()
{
    char s[65];
    while(scanf("%s",s)!=EOF){
        if(strchr(s,'.')==0)fint(atoi(s));
        else fdouble(atof(s));
    }
    return 0;
}