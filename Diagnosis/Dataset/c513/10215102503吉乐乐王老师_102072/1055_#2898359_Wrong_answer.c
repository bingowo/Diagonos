#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char albet[128];memset(albet,0,128);
    char s[100000];
    gets(s);
    char ret[100000]="\0";
    char max[100000]="\0";
    char *ps=s,*pm=max;
    while(*ps){
        if(albet[*ps]){
            *pm='\0';
            if(strlen(max)>strlen(ret))strcpy(ret,max);
            memset(albet,0,128);pm=max;
        }
        albet[*ps]++;
        *pm=*ps;
        pm++;ps++;
    }
    *pm='\0';
    if(strlen(max)>strlen(ret))strcpy(ret,max);
    printf("%s",ret);
}