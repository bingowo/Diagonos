#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char date[20];
    char time[20];
    int size;
    char name[100];

}texts;

int cmp1(const void*a,const void*b)
{
    texts A=*(texts*)a;
    texts B=*(texts*)b;
    return strcmp(A.name,B.name);

}

int cmp2(const void*a,const void*b)
{
    texts A=*(texts*)a;
    texts B=*(texts*)b;
    if(A.size!=B.size){
        return A.size-B.size;
    }else{
        return strcmp(A.name,B.name);
    }
}

int cmp3(const void*a,const void*b)
{
    texts A=*(texts*)a;
    texts B=*(texts*)b;
    if(strcmp(A.time,B.time)!=0){
        return strcmp(A.time,B.time);
    }else{
        return strcmp(A.name,B.name);
    }
}

int main()
{
    int N;
    while(scanf("%d",&N)&&(N!=0)){
        texts* p=(texts*)malloc(sizeof(texts)*N);
        for(int i=0;i<N;i++){
            scanf("%s%s%d%s",p[i].date,p[i].time,&p[i].size,p[i].name);
        }
        char s[20];
        scanf("%s",s);
        if(s[6]=='N'){
            qsort(p,N,sizeof(p),cmp1);
        }else if(s[6]=='S'){
            qsort(p,N,sizeof(p),cmp2);
        }else{
            qsort(p,N,sizeof(p),cmp3);
        }
        for(int i=0;i<N;i++){
            printf("%s %s %16d %s\n",p[i].date,p[i].time,p[i].size,p[i].name);
        }
        printf("\n");
    }
}
