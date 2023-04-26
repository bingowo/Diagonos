#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{

    return (*(char*)a)-(*(char*)b);
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    char s[201];
    char cha[201];
    for(int i=0;i<T;i++)
    {
        int temp=0;
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
        //printf("%s\n",cha);
        qsort(cha,temp,sizeof(cha[0]),cmp);
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
        for(int j=0;j<len;j++)
            printf("%c",s[j]);
        printf("\n");
    }
    return 0;
}
