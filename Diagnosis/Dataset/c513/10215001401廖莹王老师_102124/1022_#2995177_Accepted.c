#include <stdio.h>
#include <stdlib.h>
#define N 1000001
int cmp(const void*a,const void*b)
{
    char *p1,*p2,*d1,*d2;
    int i=0;
    p1=*((char **)a);
    p2=*((char **)b);
    while(*(p1+i)!='@')i++;
    d1=p1+i+1;
    i=0;
    while(*(p2+i)!='@')i++;
    d2=p2+i+1;
    if(strcmp(d1,d2)!=0)return strcmp(d1,d2);
    else return strcmp(p2,p1);
}
int main()
{
    int n;
    scanf("%d",&n);
    char ** email;
    email=(char **)malloc(n*sizeof(char*));
    char s[1000001],*p;
    int i=0,l=0;
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        l=strlen(s);
        p=(char*)malloc(l+1);
        strcpy(p,s);
       email[i]=p;
    }
    qsort(email,n,sizeof(char*),cmp);
    for(i=0;i<n-1;i++)
    {
        printf("%s\n",email[i]);
    }
    printf("%s",email[i]);
    for(i=0;i<n;i++)
    {
        p=email[i];free(p);
    }
    free(email);
    return 0;
}
