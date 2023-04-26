#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    char* p1;
    char* p2;
    p1=(char*)a;
    p2=(char*)b;
    if(*p1<91&&*p2<91)
        return (*p1-*p2);
    if(*p1>91&&*p2>91)
        return (*p1-*p2);
    if(*p1>91&&*p2<91)
        return 1;
    return -1;
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
        int j,p=0,l,l1;
        char s1[17]={0};
        for(j=0;s[j];j++)
        {
            if(a[s[j]]==0)
            {
                a[s[j]]=1;
                s1[p++]=s[j];
            }
        }
        qsort(s1,p,sizeof(char),cmp);
        printf("case #%d:\n",i);
        for(j=0;s1[j];j++)
        {
            printf("%c\n",s1[j]);
            for(l1=1;s1[j+l1];l1++)
            {
                for(l=0;s1[j+l1+l];l++)
                {
                    printf("%c",s1[j]);
                    for(p=(j+l1);(p-j-l1)<=l;p++)
                        printf("%c",s1[p]);
                    printf("\n");
                }
            }
        }
    }
}
