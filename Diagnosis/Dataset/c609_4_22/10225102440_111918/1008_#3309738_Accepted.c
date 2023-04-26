#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fint(int x){
    int a=sizeof(int);
    unsigned char *p=(unsigned char*)&x;
    while(a--){
        printf("%.2x ",*p++);
    }
    printf("\n");
}
void fdouble(double x){
    int a=sizeof(double);
    unsigned char *p=(unsigned char*)&x;
    while(a--){
        printf("%.2x ",*p++);
    }
    printf("\n");
}
int main()
{
    int t,i;
    char s[40];
    while(scanf("%s",s)!=EOF){
        if(strchr(s,'.')==0){
            fint(atoi(s));
        }
        else fdouble(atof(s));
    }
    return 0;
}
