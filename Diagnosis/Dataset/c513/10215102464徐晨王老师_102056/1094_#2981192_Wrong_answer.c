#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 130

struct data{
    char q;
   char ss[length];
};

int cmp(const void* a,const void* b){
    struct data x=*(struct data*)a;
    struct data y=*(struct data*)b;
    if(x.q==y.q&&x.q=='+'){
    if(strlen(x.ss)==strlen(y.ss))return strcmp(x.ss,y.ss);
    else return strlen(x.ss)>strlen(y.ss);
    }
    if(x.q==y.q&&x.q=='+'){
    if(strlen(x.ss)==strlen(y.ss))return strcmp(x.ss,y.ss);
    else return strlen(x.ss)>strlen(y.ss);
    }
    if(x.q=='+'&&y.q=='-')return -1;
    if(x.q=='-'&&y.q=='+')return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    struct data p[n];
    for(int i=0;i<n;i++){
        scanf("%s",p[i].ss);
        if(p[i].ss[0]=='-')p[i].q='-';
        else p[i].q='+';
    }
    qsort(p,n,sizeof(p[0]),cmp);
    for(int i=0;i<n;i++){
        printf("%s\n",p[i].ss);
    }
}
