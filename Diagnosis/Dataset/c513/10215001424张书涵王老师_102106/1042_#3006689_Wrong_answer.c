#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    char* p1;
    char* p2;
    p1=(char*)a;
    p2=(char*)b;
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        char s[17]={0};
        scanf("%s",s);
        int a[127]={0};
        int j,p=0;
        char s1[17];
        for(j=0;s[j];j++)
        {
            if(a[s[j]]==0)
            {
                a[s[j]]=1;
                s1[p++]=s[j];
            }
        }
        qsort(s1,p,sizeof(char),cmp);
    }
}