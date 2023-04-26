#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char alpha[100];
typedef struct st
{
    char s[25];
}S;
int cmp(const void * a,const void * b)
{
    S * p1=(S *)a;
    S * p2=(S *)b;
    int len1=strlen(p1->s);
    int len2=strlen(p2->s);
    int len=(len1>len2)? len1:len2;
    for(int i=0;i<len;i++)
    {
        if(p1->s[i]!=p2->s[i])
            return (alpha[p1->s[i]]-alpha[p2->s[i]]);
    }
    return (len1-len2);
}
int main()
{
    char c=getchar();
    while(c!=EOF)
    {
        S str[100];
        for(int i=0;i<52;i++)
        {
            alpha[c]=i;
            alpha[c+'a'-'A']=i;
            c=getchar();
        }
        c=getchar();
        int n=0;
        int n_len=0;
        while(c!=EOF&&c!='\n')
        {
            if(c==' ')
            {
                c=getchar();
                n++;
                n_len=0;
                continue;
            }
            if(c=='\n'||c==EOF)
                continue;
            str[n].s[n_len++]=c;
            c=getchar();
        }
        n++;
        qsort(str,n,sizeof(S),cmp);
        for(int i=0;i<n-1;i++)
        {
            printf("%s ",str[i].s);
        }
        printf("%s\n",str[n-1].s);
        if(c=='\n')
            c=getchar();
    }
    return 0;
}
