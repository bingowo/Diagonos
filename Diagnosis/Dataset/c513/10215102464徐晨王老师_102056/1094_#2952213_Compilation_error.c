#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 130;

int cmp(const void* a,const void* b){
    char* x=(char*)a;
    char* y=(char*)b;
    if(strlen(x)==strlen(y))return strcmp(x,y);
    else return strlen(x)>strlen(y);
}

int main(){
    int n;
    scanf("%d",&n);
    char s[n][length];
    char ss[length];
    for(int i=0;i<n;i++){
        scanf("%s",ss);
        if(ss[0]=='-')continue;
        else s[i]=ss;
    }
    qsort(s[0],n,sizeof(s[0]),cmp);
}