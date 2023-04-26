#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
     char* s;
     int m;
     char* t;
     int n;
}mail;

int cmp(const void*a,const void*b)
{
    char *ta=(*(mail*)a).t;
    char *tb=(*(mail*)b).t;
    if(strcmp(ta,tb)){
        return strcmp(ta,tb);
    }else{
        return  strcmp((*(mail*)b).s,(*(mail*)a).s);
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    char c1=getchar();
    mail* p=(mail*)malloc(sizeof(mail)*N);
    char smax[1000000];
    int j=0;
    for(int i=0;i<N;i++){
        p[i].s=smax+j;
        char c;
        while((c=getchar())!='@'){
            smax[j]=c;
            j++;
        }
        smax[j]='\0';
        p[i].t=smax+j;
        while((c=getchar())!='\n'){
            smax[j]=c;
            j++;
        }
        smax[j]='\0';
        j++;
    }
    qsort(p,N,sizeof(mail),cmp);
    for(int j=0;j<N;j++){
        int xh=0;
        while((p[j].s)[xh]!='\0'){
            printf("%c",(p[j].s)[xh]);
            xh++;
        }
        printf("@");
        xh=0;
        while((p[j].t)[xh]!='\0'){
            printf("%c",(p[j].t)[xh]);
            xh++;
        }
        printf("\n");
    }
    free(p);
    return 0;
}

