#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    char *A=(char*)a;
    char *B=(char*)b;
    return *A-*B;
}
int main()
{
    int cnt=0;
    char c;
    scanf("%d%c",&cnt,&c);
    for(int i=0;i<cnt;i++)
    {
        char s1[201];
        char s2[201];
        int L[200]={0};
        int t=0;
        gets(s1);
        for(int k=0;s1[k]!='\0';k++)
        {
            if(s1[k]<='Z' && s1[k]>='A')
            {
                s2[t]=s1[k];
                L[t]=k;
                t++;
            }
        }
        qsort(s2,t,sizeof(char),cmp);
        for(int k=0;k<t;k++)
        {
            s1[L[k]]=s2[k];
        }
        printf("case #%d:\n",i);
        printf("%s",s1);
    }
    return 0;
}