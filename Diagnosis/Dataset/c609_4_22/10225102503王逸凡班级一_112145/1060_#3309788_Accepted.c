#include <stdio.h>
#include <stdlib.h>
#define N 100

char *R(char *s){
    if (*s){
        char t[2*N+1],c=*s,*ps=s,*pt=t;
        int cnt;
        while(*++ps==c);
        R(ps);
        if(c<*ps){
            strcpy(pt+(cnt=(ps-s)*2),ps);
            memset(pt,c,cnt);
            strcpy(s,t);
        }
    }
    return s;
}
int main()
{
    char s[2*N+1];
    printf("%s\n",(scanf("%s",s),R(s)));
    return 0;
}
