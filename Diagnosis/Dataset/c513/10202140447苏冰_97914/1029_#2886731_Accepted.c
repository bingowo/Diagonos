#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*_a,const void*_b)
{
    char* a=(char*)_a;
    char* b=(char*)_b;
    return (*a -*b);
}
int main()
{
    int T;
    scanf("%d",&T);
    char s[210];
    char t[210];
    gets(s);
    for(int i=0;i<T;i++)
    {
        gets(s);
        int k=0;
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]>='A' && s[j]<='Z')
            {
                t[k]=s[j];
                k++;
            }
        }
        qsort(t,k,sizeof(t[0]),cmp);
        k=0;
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]>='A' && s[j]<='Z')
            {
                s[j]=t[k];
                k++;
            }
        }
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}
