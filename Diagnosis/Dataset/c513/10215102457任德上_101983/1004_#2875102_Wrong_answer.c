#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[100];
    unsigned char *c;
    double m,*m1;
    int n,*n1,size;
    scanf("%s",s);
    if(strchr(s,'.')){m=atof(s);m1=&m;c=(unsigned char*)m1;size=8;}
    else {n=atoi(s);n1=&n;c=(unsigned char*)n1;size=4;}
    while(size-->0){
        printf("%02x ",*c);
        c++;
    }
    return 0;
}