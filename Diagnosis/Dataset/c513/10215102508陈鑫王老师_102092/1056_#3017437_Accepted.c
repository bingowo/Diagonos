#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char s[15];
    int len;
}dic;
int cmp(const void*a,const void*b)
{
    dic* x=(dic*)a;
    dic*y=(dic*)b;
    return x->len>y->len?-1:1;
}
int main()
{
    int n;
    scanf("%d",&n);
    dic stand[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s",stand[i].s);
        stand[i].len=strlen(stand[i].s);
    }
    qsort(stand,n,sizeof(stand[0]),cmp);
    char s[5001];
    scanf("%s",s);
    char *p=s,*pf=NULL;
    while(*p)
    {
        int i;
        for(i=0;i<n;i++)
        {
            pf=strstr(p,stand[i].s);
            if(pf!=p)pf=NULL;
            else break;
        }
        if(pf==NULL)
        {
            printf("%c%c",*p,p==s+strlen(s)-1?'\n':' ');
            p++;
        }
        else
        {
           printf("%s%c",stand[i].s,(p+stand[i].len-1)==s+strlen(s)-1?'\n':' ') ;
           p+=stand[i].len;
        }

    }
    return 0;
}
