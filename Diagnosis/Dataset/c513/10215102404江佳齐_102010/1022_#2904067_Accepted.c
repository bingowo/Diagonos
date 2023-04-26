#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int cmp(const void* a,const void* b)
{
    char *p1,*p2,*dom1,*dom2;
    int i=0;
    p1=*((char **)a);
    p2=*((char **)b);
    while(*(p1+i)!='@') i++;
    dom1=p1+i+1;
    i=0;
    while(*(p2+i)!='@') i++;
    dom2=p2+i+1;
    if(strcmp(dom1,dom2)==0) return strcmp(p2,p1);
    else return strcmp(dom1,dom2);
}
int main()
{
    int n;
    scanf("%d",&n);
    char** email;
    email=(char**)malloc(n*sizeof(char*));
    char s[1000001],*p;
    int i,len;
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        p=(char *)malloc(len+1);
        strcpy(p,s);
        *(email+i)=p;
    }
    qsort(email,n,sizeof(char *),cmp);
    for(i=0;i<n;i++) printf("%s\n",email[i]);
    for(i=0;i<n;i++)
    {
        p=email[i];
        free(p);
    }
    free(email);
    return 0;
}

