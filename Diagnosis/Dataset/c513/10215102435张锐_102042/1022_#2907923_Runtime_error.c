#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char *s1=(char**)a,*s2=(char*)b;char *p1,*p2;
    int len1=strlen(s1),len2=strlen(s2);
    int i=0;
    while(*(s1+i)!='@') i++;
    p1=s1+i+1;
    i=0;
    while(*(s1+i)!='@') i++;
    p2=s2+i+1;
    if(strcmp(p1,p2)==0) return strcmp(s2,s1);
    else return strcmp(p1,p2);
}
int main()
{
    int t;
    scanf("%d",&t);
    char *p=(char **) malloc(t*sizeof(char *));
    for(int i=0;i<t;i++)
    {
        scanf("%s",p[i]);
    }
    qsort(p,t,sizeof(p[0]),cmp);
    for(int i=0;i<t;i++)
    {
        printf("%s",p[i]);
    }
    free(p);
    return 0;
}
