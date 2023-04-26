#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

char *getServer(char *s)
{
    while(*s!='@') s++;
    return s+1;
}

int cmp(const void*a,const void*b)
{
    int t=strcmp(getServer(*(char**)a),getServer(*(char**)b));
    return t?t:strcmp(*(char**)b,*(char**)a);
}

int main()
{
    int i,n;
    scanf("%d",&n);
    char**s=(char**)malloc(n*sizeof(char*));

    for(i=0; i<n; i++)
    {
        char t[1000001];
        scanf("%s",t);
        strcpy(s[i]=(char*)malloc(strlen(t)+1),t);
    }

    qsort(s,n,sizeof(s[0]),cmp);

    for(i=0; i<n; i++) printf("%s\n",s[i]);
    return 0;
}
