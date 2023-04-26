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
    int num=0;
    int q=0;
    int m;
    do{scanf("%d",&s[q++]);}while(m=getchar()!='\n');
    for(int i=0;i<q;i++)
    {
        int e=0;
        for(;e<num;e++)
        {
            if(s1[e]==s[i]) break;
        }
        if(e==num) s1[num++]=s[i];
    }
    if(c=='A') qsort(s1,num,4,cmp1);
    if(c=='D') qsort(s1,num,4,cmp2);
    for(int k=0;k<num;k++) printf("%d ",s1[k]);
}
