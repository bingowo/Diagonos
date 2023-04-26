#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[60];
    int cnt=0;
    double m;
    int n;
    int c;
    while(scanf("%s",s)==1){
    char* cp=s;
    while(*cp++){
        if(*cp=='.'){cnt=1;break;}
    }
    if(cnt){m=atof(s);
    c=sizeof(m);
    unsigned char *p=(unsigned char*)(&m);
    for(int j=0;j<c;j++)printf("%02x ",*p++);}
    else {
        n=atoi(s);
        c=sizeof(n);
    unsigned char *p=(unsigned char*)(&n);
    for(int j=0;j<c;j++)printf("%02x ",*p++);}
    printf("\n");
    }
    return 0;
}
