#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int cmp(const void*_a,const void*_b)
{
    char* a=(char*)_a;
    char* b=(char*)_b;
    return *a-*b;
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int cas=0;cas<T;cas++)
    {
        char s[210];
        gets(s);
        char t[210];
        int j=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                t[j++]=s[i];
            }
        }
        t[j]='\0';
        qsort(t,j,sizeof(t[0]),cmp);
        j=0;
        printf("case #%d:\n",cas);
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]>='A'&& s[i]<='Z')
            {
                printf("%c",t[j]);
                j++;
            }
            else
            {
                printf("%c",s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
