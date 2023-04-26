#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define N 100


char* insert(char* s,int pos)
{
    int i;
    for (int i = strlen(s)+1; i >pos ; i--) {
        s[i]=s[i-1];
    }
    return s;
}



int main()
{
    char s[2*N+1],t[2*N+1];
    int len,i;
    for (scanf("%s",s),len= strlen(s),i=0; i<len ; i++) {
        if(strcmp(insert(strcpy(t,s),i),s)<0) len++,i++,strcpy(s,t);
    }
    printf("%s\n",s);
    return 0;
}