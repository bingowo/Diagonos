#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    char *p1,*p2;
    p1 = *((char **)a);
    p2 = *((char **)b);
    int i = 0;
    while(*(p1+i) != '@')
        i++;
    char *q1 = p1+i+1;
    i = 0;
    while(*(p2+i) != '@')
        i++;
    char *q2 = p2+i+1;
    if(strcmp(q1,q2) == 0)
        return strcmp(p2,p1);
    else
        return strcmp(q1,q2);
}

int main()
{
    int n;
    scanf("%d",&n);
    char **email;
    email = (char **)malloc(n*sizeof(char *));
    char s[1000001],*p;
    for(int i = 0;i < n;i++)
    {
        scanf("%s",s);
        int len = strlen(s);
        p = (char *)malloc(len + 1);
        strcpy(p,s);
        *(email + i) = p;
    }
    qsort(email,n,sizeof(char *),cmp);
    for(int j = 0;j < n;j++)
        printf("%s\n",email[j]);
    for(int k = 0;k < n;k++)
    {
        p = email[k];
        free(p);
    }
    free(email);
}
