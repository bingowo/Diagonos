#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    return *(char*)a-*(char*)b;
}

int main()
{
    int T,i,k,j,cnt,cnt0,cnt1;
    char s[201],ret[201];
    int r[201];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        k=0;
        cnt1=0;
        scanf("%s",s);
        for(j=0;j<strlen(s);j++)
        {
            if(isspace(s[j]))
            {
                r[k]=j;
                k++;
            }
        }
        qsort(s,strlen(s),sizeof(char),cmp);
        for(cnt=0;s[cnt]<=20;cnt++);
        for(j=0;j<k;j++)
        {
            for(cnt0=0;cnt0<r[k];cnt0++)
            {
                ret[cnt1++]=s[cnt+cnt0];
            }
            ret[cnt1++]=' ';
        }
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}
