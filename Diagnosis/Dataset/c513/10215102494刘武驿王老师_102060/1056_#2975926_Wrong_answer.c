#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(void *a,void *b)
{
    return strcmp((char *)a,(char *)b);
}
int main()
{
    int n;
    scanf("%d",&n);
    char words[5000][16];
    int max=0;
    for(int i=0;i<n;i++) scanf("%s",words[i]);
    qsort(words,n,sizeof(words[0]),cmp);
    char s[6000];
    scanf("%s",s);
    int p;
    for(int i=0;i<strlen(s);i++)
    {
        int j;
        int test=0;
        char m[40];
        for(j=n-1;j>=0;j--)
        {
            for(p=0;p<strlen(words[j]);p++) m[p]=s[i+p];
            m[p]='\0';
            if(strcmp(m,words[j])==0)
            {
                break;
            }
        }
        if(j==0)
        {
            printf("%c ",s[i]);
            continue;
        }
        printf("%s ",m);
        i+=(p-1);
    }
}
