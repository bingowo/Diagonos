#include<stdio.h>
#include<string.h>
void sint(int n);
void sdouble(double d);
int main()
{
    char s[31];
    while(scanf("%s",s)!=EOF){
        if(strchr(s,'.')==0)sint(atoi(s));
        else sdouble(atof(s));
    }
    return 0;
}
void sint(int n){
    int c=sizeof(n);
    unsigned char * p=(unsigned char *)&n;
    while(c--)printf("%02x ",*p++);
    printf("\n");
}
void sdouble(double d){
    int c=sizeof(d);
    unsigned char *p =(unsigned char *)&d;
    while(c--)printf("%02x ",*p++);
    printf("\n");
}
