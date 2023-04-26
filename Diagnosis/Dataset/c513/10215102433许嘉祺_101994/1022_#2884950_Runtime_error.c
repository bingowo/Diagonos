#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
    char*s1=*(char**)a;
    char*s2=*(char**)b;
    int i=0;
    while (*(s1+i)!='@') i++;

    char *p1=s1+i+1;
    i=0;
    while (s2[i]!='@') i++;

    char* p2=s2+i+1;
    if (strcmp(p1,p2)==0)
        return(strcmp(s2,s1));
    else return(strcmp(p1,p2));

}
int main()
{
    char s[1000100];
    char*s1[101];
    int n,t=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%s",s+t);
        s1[i]=s+t;
        t+=strlen(s1[i])+1;

    }
    qsort(s1,n,sizeof(char*),cmp);
    for (int i=0;i<n;i++)
    {
        printf("%s\n",s1[i]);
    }
    return 0;
}
