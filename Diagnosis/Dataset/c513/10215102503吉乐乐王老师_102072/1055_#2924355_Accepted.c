#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char albet[128];memset(albet,0,128);
    char s[1000001];
    gets(s);
    char ret[1000001]="\0";
    char *max=(char*)malloc(1000001);
    char *ps=s,*pm=max;
    while(*ps){
        if(albet[*ps]){
            *pm='\0';
            if(strlen(max)>strlen(ret))strcpy(ret,max);
            int pt=strchr(max,*ps)-max;
            // for(int i=0;i<strlen(max);i++){
            //     if(max[i]==*ps){
            //         pt=i;break;
            //     }
            // }
            for(int i=0;i<=pt;i++){
                albet[max[i]]--;
            }
            max=max+pt+1;
        }
        albet[*ps]++;
        *pm=*ps;
        pm++;ps++;
    }
    *pm='\0';
    if(strlen(max)>strlen(ret))strcpy(ret,max);
    printf("%s",ret);
}