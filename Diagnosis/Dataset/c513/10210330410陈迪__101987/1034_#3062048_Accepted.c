#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float alphat[58];
int cmp(const void *a, const void *b)
{
    char* a1=(char*)a;
    char* b1=(char*)b;
    if(alphat[*a1-65]-alphat[*b1-65]!=0)
        return (alphat[*a1-65]>alphat[*b1-65])?-1:1;
    else
    {
        if(abs((int)*a1-(int)*b1)==32)
            return *a1>*b1?-1:1;
        else
            return *a1>*b1?1:-1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    char s[101];
    for(int i=0;i<T;i++)
    {
        for(int j=0;j<26;j++)
        {
            scanf("%f",&alphat[j]);
            alphat[j+32] = alphat[j];
        }
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(char),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }

    return 0;
}