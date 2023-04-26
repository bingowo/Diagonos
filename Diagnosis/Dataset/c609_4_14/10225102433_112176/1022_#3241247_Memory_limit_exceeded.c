#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
     char* s;
//     int m;
     char* t;
//     int n;
}mail;

int cmp(const void*a,const void*b)
{
    char *ta=(*(mail*)a).t;
    char *tb=(*(mail*)b).t;
    if(strcmp(ta,tb) != 0){
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
        char* s1=(char*)malloc(1000000*sizeof(char));
        char* t1=(char*)malloc(1000000*sizeof(char));
        while((c=getchar())!='@'){
            s1[j]=c;
            j++;
        }
        s1[j]='@';
        s1[j+1] = '\0';
        p[i].s = s1;
//        p[i].m=j;
        j=0;
        while((c=getchar())!='\n'){
            t1[j]=c;
            j++;
        }
        p[i].t = t1;
        p[i].t[j] = '\0';
    }
    qsort(p,N,sizeof(mail),cmp);
    for(int j=0;j<N;j++){
        printf("%s",p[j].s);
        printf("%s",p[j].t);
//        char* s2=p[j].s;
//        char* t2=p[j].t;
//        int x=p[j].m;
//        int y=p[j].n;
//        for(int i=0;i<x;i++)
//            printf("%c",s2[i]);
//        for(int k=0;k<y;k++)
//            printf("%c",t2[k]);
        printf("\n");
    }
    free(p);
    return 0;
}

