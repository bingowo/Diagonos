#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    char *a1=*(char (*)[301])a,*b1=*(char (*)[301])b;

    char domin1[300],domin2[300];
    int i;
    for(i=7;i< strlen(a1);i++)
    {
        if(a1[i] != '/')
            domin1[i-7]=a1[i];
        else
            break;
    }
    domin1[i-7]='\0';

    for(i=7;i< strlen(b1);i++)
    {
        if(b1[i] != '/')
            domin2[i-7]=b1[i];
        else
            break;
    }
    domin2[i-7]='\0';

    if(strcmp(domin1,domin2)==0)
        return strcmp(a1,b1);
    else
        return strcmp(domin1,domin2);
}
int main() {
    int n;
    scanf("%d",&n);
    char s[100][301];
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        char t[301];
        scanf("%s",t);
        if(t[4] == ':')
            strcpy(s[cnt++],t);
    }
    qsort(s,cnt,sizeof (s[0]),cmp);
    for(int i=0;i<cnt;i++)
        printf("%s\n",s[i]);
    return 0;
}
