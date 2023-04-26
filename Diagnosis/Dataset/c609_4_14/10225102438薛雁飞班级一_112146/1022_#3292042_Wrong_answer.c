#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct p{char x[100];char y[100];};
typedef struct p pair;
int cmp(const void* a,const void* b)
{
    pair p1,p2;
    int k;
    char *s1,*s2;
    s1=(char*)a;s2=(char*)b;
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
    if(strcmp(p1.y,p2.y)==1) return(-strcmp(p1.x,p2.x));
    else return(strcmp(p1.y,p2.y));
}
int main()
{
    int n,i;
    scanf("%d",&n);
    char s[100][100];
    for(i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int j=0;j<i;j++){
        printf("%s\n",s[j]);
    }
    return 0;
}
