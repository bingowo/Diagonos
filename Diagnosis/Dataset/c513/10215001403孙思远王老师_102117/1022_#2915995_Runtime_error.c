#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    char *p1,*p2,*point1,*point2;
    int i;
    p1=*((char **)a);
    p2=*((char **)b);
    i=0;
    while(*(p1+i)!='@')
        i++;
    point1=p1+i+1;
    i=0;
    while(*(p2+i)!='@')
        i++;
    point2=p2+i+1;
    if(strcmp(point1,point2)==0)
        return strcmp(p2,p1);
    else
        return strcmp(point1,point2);
}

int main()
{
    int n;
    char **email;
    scanf("%d",&n);
    email=(char **)malloc(n*sizeof(char *));
    char s[1000001],*p;
    int i,len;
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        p=(char *)malloc(len+1);
        strcpy(p,s);
        *(email[i])=p;
    }
    qsort(email,n,sizeof(char *),cmp);
    for(i=0;i<n;i++)
        printf("%s\n",email[i]);
    for(i=0;i<n;i++)
    {
        p=email[i];
        free(p);
    }
    free(email);
    return 0;
}
