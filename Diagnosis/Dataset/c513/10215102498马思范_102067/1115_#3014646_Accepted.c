#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
{
    return *(char*)a - *(char*)b;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[22]= {'0'};
        scanf("%s",s+1);
        int minx='9'+1,pos,xi;
        for (pos=strlen(s)-1; pos>0&&s[pos-1]>=s[pos]; pos--);
        int p=s[pos-1];
        for (int j=strlen(s)-1; j>=pos; j--)
            if (s[j]>p&&s[j]<minx) minx=s[j],xi=j;
        s[pos-1]=minx;
        s[xi]=p;
        qsort(s+pos,strlen(s)-pos,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s[0]=='0'?s+1:s);
    }
    return 0;
}
