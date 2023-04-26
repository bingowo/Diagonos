#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void*b)
{
    return *(char*)a - *(char*)b;
}
int main()
{
    
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {char s[22] = {'0'};
    scanf("%s",s+1);
    int minx = '9'+1,pos,xi;
    for(pos = strlen(s)-1;pos>0&&s[pos-1]>=s[pos];pos--);
    int p = s[pos-1],j;
    for(j = strlen(s)-1;j>=pos;j--)
        if(s[j]>p&&s[j]<minx) minx = s[j],xi = j;
    s[pos-1] = minx;
    s[xi] = p;
    qsort(s+pos,strlen(s)-pos,sizeof(char),cmp);
    printf("case #%d:\n%s\n",i,s[0]=='0'?s+1:s);}
    return 0;
}
