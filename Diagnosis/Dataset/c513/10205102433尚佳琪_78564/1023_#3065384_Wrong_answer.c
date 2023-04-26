#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[50];
    int cnt;
    int flag;
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.cnt!=s2.cnt)
        return s1.cnt-s2.cnt;
    else
    {
        if(s1.flag!=s2.flag)
            return s1.flag-s2.flag;
        else
             return strcmp(s1.s,s2.s);
    }
}

int main()
{
    node a[150];
    int k=0;
    while(scanf("%s",a[k].s)!=EOF)
    {
        int len=strlen(a[k].s);
        a[k].cnt=0;
        a[k].flag=0;
        for(int i=0;i<len;i++)
        {
            if(a[k].s[i]>='0'&&a[k].s[i]<='9')
                a[k].cnt=a[k].cnt*10+a[k].s[i]-'0';
            if(a[k].s[i]=='0')
                a[k].flag=1;
        }
        k++;
    }
    qsort(a,k,sizeof(a[0]),cmp);
    for(int i=0;i<k;i++)
        printf("%s ",a[i].s);
}
