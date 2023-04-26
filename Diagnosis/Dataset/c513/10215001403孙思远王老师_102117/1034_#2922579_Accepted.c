#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double pr[26]={0};
int cmp(const void *a,const void *b)
{
    char p1,p2;
    p1=*(char *)a;
    p2=*(char *)b;
    int n1,n2,u1=0;
    if(p1>='a')
        n1=p1-'a';
    else
        {
            n1=p1-'A';
            u1=1;
        }
    if(p2>='a')
        n2=p2-'a';
    else
        {
            n2=p2-'A';
        }
    if(n1!=n2)
    {
        if(pr[n1]>pr[n2])
            return -1;
        else
            return 1;
    }
    else
    {
        if(u1==1)
            return 1;
        else
            return -1;
    }
}
int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int i;
        for(i=0;i<26;i++)
        {
            scanf("%lf",&pr[i]);
        }
        char s[101];
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        printf("%s\n",s);
    }
    return 0;
}
