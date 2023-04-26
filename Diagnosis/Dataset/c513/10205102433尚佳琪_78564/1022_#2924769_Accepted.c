#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char *s1,*s2;
    s1=*(char **)a;
    s2=*(char **)b;
    char* len1,*len2;
    int i=0;
    while(s1[i]!='@')
    {
        i++;
    }
    len1=s1+i+1;
    i=0;
    while(s2[i]!='@')
    {
        i++;
    }
    len2=s2+i+1;
    if(strcmp(len1,len2)==0)
        return strcmp(s2,s1);
    else
        return strcmp(len1,len2);
}
int main()
{
    int n;
    scanf("%d",&n);
    char **email;
    email=(char **)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++)
    {
       char s[1000001],*p;
        scanf("%s",s);
        int len=strlen(s);
        p=(char *)malloc((len+1)*sizeof(char));
        strcpy(p,s);
        email[i]=p;
    }
    qsort(email,n,sizeof(email[0]),cmp);
    for(int i=0;i<n;i++)
        printf("%s\n",email[i]);
    return 0;
}
