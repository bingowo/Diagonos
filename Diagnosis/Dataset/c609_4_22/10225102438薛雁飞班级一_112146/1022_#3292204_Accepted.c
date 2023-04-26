#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a,const void* b)
{

    char *s1,*s2,*p1,*p2;
    int i=0;
    s1=*((char**)a);s2=*((char**)b);
    while(*(s1+i)!='@')i++;
    p1=s1+i+1;
    i=0;
    while(*(s2+i)!='@')i++;
    p2=s2+i+1;
    if(strcmp(p1,p2)==0)return(strcmp(s2,s1));
    else return strcmp(p1,p2);
}
int main()
{
    int n;
    scanf("%d",&n);
    char **s;
    s=(char**)malloc(n*sizeof(char*));
    char *p,a[1000001];
    for(int i=0;i<n;i++){
        scanf("%s",a);
        int len=strlen(a);
        p=(char*)malloc(len+1);
        strcpy(p,a);
        *(s+i)=p;
    }
    qsort(s,n,sizeof(char*),cmp);
    for(int i=0;i<n;i++){
        printf("%s\n",s[i]);
    }
    return 0;
}
