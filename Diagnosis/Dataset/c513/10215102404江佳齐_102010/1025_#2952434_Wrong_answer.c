#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct S
{
    char str[21];
    int dif;
}s[100];

int cmp(const void*a, const void *b)
{
    struct S s1,s2;
    s1=*((struct S*)a);
    s2=*((struct S*)b);
    if(s1.dif!=s2.dif) return s2.dif-s1.dif;
    else
    {
        if(s1.str>s2.str) return 1;
        else return -1;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        char alpha[26];
        for(int j=0;j<26;j++) alpha[j]=0;
        for(int j=0;j<n;j++)
        {
            scanf("%s",s[j].str);
            int len=strlen(s[j].str);
            for(int m=0;m<len;m++)
            {
                if(alpha[s[j].str[m]-'A']==0)
                {
                    alpha[s[j].str[m]-'A']==1;
                    s[j].dif++;
                }
            }
        }
        qsort(s,n,sizeof(s[0]),cmp);
        for(int x=0;x<n;x++)
            printf("%s\n",s[x].str);
    }
    return 0;
}
