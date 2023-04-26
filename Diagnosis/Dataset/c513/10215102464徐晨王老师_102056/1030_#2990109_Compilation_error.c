#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char c;
    char c0;
    char s[20];
    char ss[20];
};

int cmp(const void* a,const void* b){
    struct data x=*(struct data*)a;
    struct data y=*(struct data*)b;
    if(x.c0==y.c0){
        if(x.c==y.c){
            if(x.c=='+')return strcmp(x.s,y.s);
            if(x.c=='-')return strcmp(y.s,x.s);
        }
        else{
            if(x.c=='+')return 1;
            else return -1;
        }
    }
    else return x.c0<y.c0;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N;
        scanf("%d",&N);
        struct data p[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<19;j++){
                p[i].s[j]='0';
            }
            scanf("%s",p[i].ss);
            if(p[i].ss[0]=='-'){
                p[i].c='-';
                p[i].c0=s[1];
            }
            else{
                p[i].c0=p[i].ss[0];
                p[i].c='+';
            }
            for(int j=0;j<strlen(p[i].ss);j++){
                p[i].s[19-strlen(ss)+j]=p[i].ss[j];
                if(p[i].s[19-strlen(ss)+j]=='-')p[i].s[19-strlen(ss)+j]='0';
            }
        }
        qsort(p,N.sizeof(p[0]),cmp);
        for(int i=0;i<N;i++){
            printf("%s ",p[i].ss);
        }
        printf("case #%d:\n",t);

    }
}