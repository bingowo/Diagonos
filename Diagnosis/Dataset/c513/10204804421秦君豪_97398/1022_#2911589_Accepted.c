#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void *b)
{
    char *a1=*((char**)a);
    char *b1=*((char**)b);
    char *d1,*d2;
    int i=0;
    while(*(a1+i)!='@') i++;
    d1=a1+i+1;
    i=0;
    while(*(b1+i)!='@') i++;
    d2=b1+i+1;
    if (strcmp(d1,d2)==0) return strcmp(b1,a1);
    else return strcmp(d1,d2);
}
int main(void)
{
    char **email;
    int n;
    int i;
    scanf("%d",&n);
    email=(char **)malloc(n*sizeof(char *));
    char s[1000001],*p;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int len = strlen(s);
        p=(char*)malloc(len+1);
        strcpy(p,s);
        *(email+i)=p;
    }
    qsort(email, n, sizeof(char *), cmp);
    for(i=0;i<n;i++)  printf("%s\n",email[i]);

    return 0;
}
