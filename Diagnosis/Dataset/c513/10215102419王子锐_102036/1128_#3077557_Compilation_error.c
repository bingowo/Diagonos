#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    char *p=*(char(*)[301])a,*q=*(char(*)[301])b;
    char domain1[300],domain2[300];
    int i;
    for(i=7;i<strlen(p);i++)
        if(p[i]!='/') domain1[i-7]=p[i];
        else break;
    domain1[i-7]='\0';
    for(i=7;i<strlen(q);i++)
        if(q[i]!='/') domain2[i-7]=q[i];
        else break;
    domain2[i-7]='0';
    if(strcmp(domain1,domain2)==0)
        return strcmp(p,q);
    else
        return strcmp(domain1,domain2);
}
int main()
{
    int n;scanf("%d",&n);
    char s[100][301];int cnt=0;
    for( int i=0;i<n;i++)
    {
        char t[301];scanf("%s",t);
        if(t[4]!='s') strcpy(s[cnt++],t);
    }
    qsort(s,cnt,sizeof(s[0]),cmp),
    for(int i=0;i<cnt;i++)
        printf("%s\n",s[i]);
    return 0;
}

