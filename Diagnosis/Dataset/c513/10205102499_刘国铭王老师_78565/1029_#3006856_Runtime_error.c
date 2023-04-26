#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    return strcmp(*(char*)a,*(char*)b);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int temp=0;
        char s[201];
        char cha[201];
        gets(s);
        //printf("%s\n",s);
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                cha[temp]=s[i];
                temp++;
            }
        }
        qsort(cha,len,sizeof(char),cmp);
        //printf("%s\n",cha);
        int temp1=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
               s[i]=cha[temp1];
                temp1++;
            }
        }
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}
