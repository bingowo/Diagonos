#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int cmp(const void* a,const void* b)
{
    char *x=*(char**)a;
    char *y=*(char**)b;
    int p1=0,p2=0;
    while(x[p1]!='@')p1++;
    while(y[p2]!='@')p2++;
    char* d1,*d2;
    d1=x+p1+1;
    d2=y+p2+1;
    if(strcmp(d1,d2)==0)return strcmp(y,x);
    else return strcmp(d1,d2);
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[1000001];
    char *p;
    char** a=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        scanf("%s",s);
        int len=strlen(s)+1;
        p=(char*)malloc(len);
        strcpy(p,s);
        *(a+i)=p;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n;i++){
        printf("%s\n",a[i]);
    }
    for(int i=0;i<n;i++){
        p=a[i];
        free(p);
    }
    free(a);
    return 0;
}