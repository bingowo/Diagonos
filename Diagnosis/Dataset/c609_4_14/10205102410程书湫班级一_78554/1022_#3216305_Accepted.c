#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char *p1,*p2,*domain1,*domain2;
    int i=0;
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
    int n;
    scanf("%d",&n);
    char** email;
    email=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++)
    {
        char s[1000001];
        scanf("%s",s);
        int len=strlen(s);
        char *p=(char*)malloc(len+1);
        strcpy(p,s);
        *(email+i)=p;
    }

    qsort(email,n,sizeof(char*),cmp);

    for(int i=0;i<n;i++)
        printf("%s\n",email[i]);
    for(int i=0;i<n;i++)
    {
        char* p=email[i];
        free(p);
    }
   free(email);
    return 0;
}
