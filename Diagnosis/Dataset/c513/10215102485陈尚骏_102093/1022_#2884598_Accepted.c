#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int cmp(const char *a,const char *b)
{
    int i=0;
    char *p1,*p2,*domain1,*domain2;
    p1=*((char**)a);
    p2=*((char**)b);
    while(*(p1+i)!='@') i++;
    domain1=p1+i+1;
    i=0;
    while(*(p2+i)!='@') i++;
    domain2=p2+i+1;
    if(strcmp(domain1,domain2)==0) return strcmp(p2,p1);
    else return strcmp(domain1,domain2);
}

int main()
{
    int n,i=0;
    scanf("%d",&n);
    char **email;
    char s[1000001],*p;
    email=(char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++)
    {
        scanf("%s",&s);
        int len=strlen(s);
        p=(char*)malloc(len+1);
        strcpy(p,s);
        *(email+i)=p;
    }
    qsort(email,n,sizeof(char*),cmp);
    for(int j=0;j<n;j++)
        printf("%s\n",email[j]);
    for(int j=0;j<n;j++)
    {
        p=email[j];
        free(p);
    }
    free(email);
    return 0;
}
