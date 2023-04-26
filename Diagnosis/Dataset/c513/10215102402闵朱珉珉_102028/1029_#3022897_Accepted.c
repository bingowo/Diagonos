#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char *a1=(char *)a,*b1=(char *)b;
    return *a1-*b1;
}
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int q=0;q<T;q++)
    {
        char s[250];
        int i,j=0;
        gets(s);
        int len=strlen(s);
        char S[250];
        for(int g=0;g<200;g++)
        {
            S[g]='a';
        }
        char a[200];
        int count=0;
        for(i=0;i<len;i++)
        {
            if(s[i]<='Z'&&s[i]>='A')
            {
                a[j]=s[i];
                j++;
                count++;
            }
            else
            {
                S[i]=s[i];
            }
        }
        qsort(a,count,sizeof(a[0]),cmp);
        i=0;
        j=0;
        for(int k=0;k<len;k++)
        {
            if(S[k]=='a')
            {
                S[k]=a[j];
                j++;
            }
        }
        printf("case #%d:\n",q);
        for(int t=0;t<len;t++)
            printf("%c",S[t]);
        printf("\n");
    }
    return 0;
}
