#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char albet[128];memset(albet,0,128);
    char s[1000];
    gets(s);
    char ret[1000]="\0";
    char *max=(char*)malloc(1000);memset(max,-1,1000);
    char *ps=s,*pm=max;
    while(*ps){
        if(albet[*ps]){
            *pm='\0';
            if((pm-max)>strlen(ret))
            strcpy(ret,max);
            char *pt;
            for(int i=0;i<strlen(max);i++){
                if(max[i]==*ps){
                    pt=max+i;break;
                }
            }
            max=pt+1;
            for(int i=0;i<strlen(max);i++){
                albet[max[i]]--;
            }
            albet[*ps]--;
        }
        albet[*ps]++;
        *pm=*ps;
        pm++;ps++;
    }
    *pm='\0';
    if(albet[*(ps-1)]<2)
        if((pm-max)>strlen(ret))
            strcpy(ret,max);
    printf("%s",ret);
}