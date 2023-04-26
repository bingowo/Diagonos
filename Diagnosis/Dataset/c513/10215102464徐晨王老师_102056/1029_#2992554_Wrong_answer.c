#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct data{
    int pos;
    char ss[2];
};

int cmp(const void* a,const void* b){
    struct data x=*(struct data*)a;
    struct data y=*(struct data*)b;
    if(isupper(x.ss[0])&&isupper(y.ss[0])){
        return x.pos>y.pos;
    }
    else{
        return strcmp(x.ss,y.ss);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    char c=getchar();
    for(int t=0;t<T;t++){
        char s[210];
        gets(s);
        struct data p[210];
        for(int i=0;i<strlen(s);i++){
            p[i].pos=i;
            p[i].ss[0]=s[i];
        }
        qsort(p,strlen(s),sizeof(p[0]),cmp);
        printf("case #%d:\n",t);
        for(int i=0;i<strlen(s);i++){
            printf("%s",p[i].ss);
        }
        printf("\n");
    }
}