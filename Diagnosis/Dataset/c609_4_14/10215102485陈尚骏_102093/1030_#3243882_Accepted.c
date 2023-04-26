#include <stdio.h>
#include <stdlib.h>
#include<string.h>

float alph[58];

int cmp(const void*a,const void*b)
{
    char*a1=(char*)a;
    char*b1=(char*)b;
    if(alph[*a1-65]-alph[*b1-65]!=0)
    {
        if(alph[*a1-65]>alph[*b1-65]) return -1;
        else  return 1;
    }
    else
    {
        if(abs((int)*a1-(int)*b1)==32)
        {
            if(*a1>*b1) return -1;
            else return 1;
        }
        else
        {
            if(*a1>*b1) return 1;
            else return -1;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    char s[101];
    for(int i=0;i<T;++i)
    {
        for(int j=0;j<26;++j)
        {
            scanf("%f",&alph[j]);
            alph[j+32]=alph[j];
        }
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}