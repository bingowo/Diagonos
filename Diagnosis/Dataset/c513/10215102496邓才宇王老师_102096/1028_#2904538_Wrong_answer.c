#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp1(const void *p1,const void *p2)
{
    int* a=p1;
    int* b=p2;
    return *a-*b;
}
int cmp2(const void *p1,const void *p2)
{
    int* a=p1;
    int* b=p2;
    return *b-*a;
}
int main()
{
    char c;
    scanf("%c\n",&c);
    int s[101];
    int s1[101];
    int num=1;
    int q=0;
    int m;
    while(scanf("%d ",&m)!=EOF)
        s[q++]=m;
    s1[0]=s[0];
    for(int i=0;i<strlen(s);i++)
    {
        for(int j=0;j<strlen(s1);j++)
        {
            if(s1[j]!=s[i]) s1[num++]=s[i];
        }
    }
    if(c=='A') qsort(s1,strlen(s1),4,cmp1);
    if(c=='D') qsort(s1,strlen(s1),4,cmp2);
    for(int k=0;k<strlen(s1);k++) printf("%d ",s1[k]);
}
