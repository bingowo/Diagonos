#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[50];
    int cnt;
    char cont[50];
   // int flag;
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.cnt!=s2.cnt)
        return s1.cnt-s2.cnt;
    else
    {
        if(strcmp(s1.cont,s2.cont)!=0)
            return strcmp(s1.cont,s2.cont);
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
        int t=0;
        for(int i=0;i<len;i++)
        {
            if(a[k].s[i]>='0'&&a[k].s[i]<='9')
            {
                a[k].cnt=a[k].cnt*10+a[k].s[i]-'0';
                a[k].cont[t++]=a[k].s[i];
                //a[k].flag++;
            }
        }
        a[k].cont[t]='\0';
        k++;
    }
    qsort(a,k,sizeof(a[0]),cmp);
    for(int i=0;i<k;i++)
        printf("%s ",a[i].s);
}
