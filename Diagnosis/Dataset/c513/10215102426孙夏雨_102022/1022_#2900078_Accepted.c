#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p3,const void* p4)
{
    char* p1=*((char** )p3);
    char* p2=*((char** )p4);
    char* d1,*d2;
    int i=0;
    while(*(p1+i)!='@') i++;
    d1=p1+i+1;
    i=0;
    while(*(p2+i)!='@') i++;
    d2=p2+i+1;
    if(strcmp(d1,d2)>0) return 1;
    else if(strcmp(d1,d2)<0) return -1;
    else{
        if(strcmp(p1,p2)>0) return -1;
        else return 1;
    }
}

int main()
{
    int n=0;
    scanf("%d",&n);
    char s[1000001], *p1;
    char** p=(char** )malloc(n*sizeof(char* ));
    for(int t=0;t<n;t++) {
        scanf("%s",s);
        int len=strlen(s);
        p1=(char* )malloc((len+1)*sizeof(char));
        strcpy(p1,s);
        *(p+t)=p1;
    }
    qsort(p,n,sizeof(char* ),cmp);
    for(int jj=0;jj<n;jj++) printf("%s\n",*(p+jj));
    for(int rr=0;rr<n;rr++) {
        p1=p[rr];
        free(p1);
    }
    free(p);
    return 0;
}
