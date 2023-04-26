#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char albet[128];memset(albet,0,128);
    char s[100000];
    gets(s);
    char *ret=(char*)malloc(100000);*ret='\0';
    char *max=(char*)malloc(100000);
    char *ps=s,*pm=max;
    while(*ps){
        if(albet[*ps]){
            *pm='\0';
            if((pm-max)>strlen(ret))strcpy(ret,max);
            int len=pm-(strchr(max,*ps)+1);
            max=strchr(max,*ps)+1;
            pm=max+len;
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