#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char users[2000];
    char zhuji[2000];
}MAIL;

int cmp(const void* p3,const void* p4)
{
    MAIL* p1=(MAIL* )p3;
    MAIL* p2=(MAIL* )p4;
    int k=strcmp(p1->users,p2->users);
    int w=strcmp(p1->zhuji,p2->zhuji);
    if(w<0) return -1;
    else if(w>0) return 1;
    else{
        if(k<0) return 1;
        else return -1;
    }
}

int main()
{
    int n=0;
    scanf("%d",&n);
    getchar();
    MAIL* p=(MAIL* )malloc(n*sizeof(MAIL));
    char c;
    for(int t=0;t<n;t++){
        int i=0;
        while((c=getchar())!='@') {(p+t)->users[i]=c;i++;}
        i=0;
        while((c=getchar())!='\n') {(p+t)->zhuji[i]=c;i++;}
    }
    qsort(p,n,sizeof(MAIL),cmp);
    for(int ii=0;ii<n;ii++) printf("%s@%s\n",(p+ii)->users,(p+ii)->zhuji);
    free(p);
    return 0;
}
