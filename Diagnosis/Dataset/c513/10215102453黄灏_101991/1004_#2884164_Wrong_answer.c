#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ans_int(int n){
    int c=sizeof(n);
    unsigned char* p=(unsigned char*)&n;
    while(c--){
        printf("%02x",*p++);
        printf("\n");
    }

}


void ans_double(double m){
    int c=sizeof(m);
    unsigned char* p=(unsigned char*)&m;
    while(c--){
        printf("%02x",*p++);
        printf("\n");
    }
}

int main()
{
    char s[31];
    while(scanf("%s",s)!=EOF){
        if(strchr(s,'.')==0) ans_int(atoi(s));
        else ans_double(atof(s));
    }
    return 0;
}
