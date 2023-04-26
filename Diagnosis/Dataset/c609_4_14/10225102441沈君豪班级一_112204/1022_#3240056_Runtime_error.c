#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
     char s[100];
     char t[100];
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
    for(int i=0;i<N;i++){
        int j=0;
        char c;
        char* s1=p[i].s;
        char* t1=p[i].t;
        while((c=getchar())!='@'&&c!='\n'){
            s1[j]=c;
            j++;
        }
        s1[j]='@';
        j=0;
        while((c=getchar())!='\n'){
            t1[j]=c;
            j++;
        }
    }
    qsort(p,N,sizeof(mail),cmp);
    for(int j=0;j<N;j++){
        char* s2=p[j].s;
        char* t2=p[j].t;
        int x=strlen(s2);
        int y=strlen(t2);
        for(int i=0;i<x;i++)
            printf("%c",s2[i]);
        for(int k=0;k<y;k++)
            printf("%c",t2[k]);
        printf("\n");
    }
    free(p);
    return 0;
}
