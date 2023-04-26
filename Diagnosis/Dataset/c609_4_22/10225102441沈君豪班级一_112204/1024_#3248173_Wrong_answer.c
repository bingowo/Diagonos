#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char date[20];
    char time[20];
    long long int size;
    char name[120];

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
            scanf("%s %s %lld %s",p[i].date,p[i].time,&p[i].size,p[i].name);
        }
        char s[10],s1[10];
        scanf("%s",s1);
        scanf("%s",s);
        if(s[1]=='N'){
            qsort(p,N,sizeof(texts),cmp1);
        }else if(s[1]=='S'){
            qsort(p,N,sizeof(texts),cmp2);
        }else{
            qsort(p,N,sizeof(texts),cmp3);
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<strlen(p[i].date);j++)
                printf("%c",(p[i].date)[j]);
            printf(" ");
            for(int j=0;j<strlen(p[i].time);j++)
                printf("%c",(p[i].time)[j]);
            printf(" ");
            printf("%16lld",p[i].size);
            printf(" ");
            for(int j=0;j<strlen(p[i].name);j++)
                printf("%c",(p[i].name)[j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
