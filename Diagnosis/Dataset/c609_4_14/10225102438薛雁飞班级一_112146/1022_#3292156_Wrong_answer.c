#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct p{char x[100000];char y[1000000];};
typedef struct p pair;
int cmp(const void* a,const void* b)
{
    pair p1,p2;
    int k;
    char *s1,*s2;
    s1=*((char**)a);s2=*((char**)b);
    for(int j=0;j<strlen(s1);j++){
        if(s1[j]=='@'){k=j;break;}
    }
    for(int j=0;j<k;j++){
        p1.x[j]=s1[j];
    }
    for(int j=k+1;j<strlen(s1);j++){
        p1.y[j-k-1]=s1[j];
    }

    for(int j=0;j<strlen(s2);j++){
        if(s2[j]=='@'){k=j;break;}
    }
    for(int j=0;j<k;j++){
        p2.x[j]=s2[j];
    }
    for(int j=k+1;j<strlen(s2);j++){
        p2.y[j-k-1]=s2[j];
    }
    if(strcmp(p1.y,p2.y)==1) return(strcmp(p2.x,p1.x));
    else return(strcmp(p1.y,p2.y));
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
