#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    char *p1=*(char **)a,*p2=*(char **)b;
    char *domain1,*domain2;
    int i=0;
    while(*(p1+i)!='@')i++;
    domain1=p1+i+1;
    i=0;
    while(*(p2+i)!='@')i++;
    domain2=p2+i+1;
    if(strcmp(domain1,domain2)==0)
        return strcmp(p2,p1);
    else return strcmp(domain1,domain2);
}

int main()
{
    int n;
    scanf("%d",&n);
    char **email,*s;
    email=(char **)malloc(n*sizeof(char *));
    s=(char *)malloc(10000*sizeof(char));
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        email[i]=(char *)malloc(strlen(s)*sizeof(char)+1);
        strcpy(email[i],s);
    }
    qsort(email,n,sizeof(char *),cmp);
    for(int i=0;i<n;i++)
        printf("%s\n",email[i]);
    return 0;
}