#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    char *pa=*(char**)a,*pb=*(char**)b,*p1,*p2;
    int i=0;
    while(*(pa+i)!='@')  i++;
    p1=pa+i;
    i=0;
    while(*(pb+i)!='@')  i++;
    p2=pb+i;

    if(strcmp(p1,p2)==0)  return strcmp(pb,pa);
    else  return strcmp(p1,p2);
}
int main()
{
    int n,i,j;
    char s[100010];
    scanf("%d",&n);
    char **email=(char**)malloc(n*sizeof(char*));
    char *p;
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        p=(char*)malloc(strlen(s)+1);
        strcpy(p,s);
        *(email+i)=p;
    }
    qsort(email,n,sizeof(char*),cmp);
    for(i=0;i<n;i++)
    {
        printf("%s\n",email[i]);
    }
    for(i=0;i<n;i++)
    {
        p=email[i];
        free(p);
    }
    free(email);
    return 0;
}