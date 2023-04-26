#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char* s=(char*)malloc(sizeof(char)*1000001);
    gets(s);
    char* max=s;
    char* now=s;
    int lenmax=0;
    int lennow=0;

    for (int i=0;i<strlen(s);i++){
        if (strchr(now,s[i])>=s+i||strchr(now,s[i])==NULL) lennow++;
        else {
            now=strchr(now,s[i])+1;lennow=s+i-now+1;
        }
        if (lenmax<lennow) {lenmax=lennow;max=now;}
    }
    for (int i=0;i<lenmax;i++) printf("%c",max[i]);
    free(s);
    return 0;
}