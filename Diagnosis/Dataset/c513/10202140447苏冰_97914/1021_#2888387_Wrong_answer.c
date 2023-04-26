#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int a[130];
int strcmp1(const char* p1,const char* p2)
{
    while(*p1 == *p2)
    {
        p1++;p2++;
    }
    if(*p1=='\0' && *p2!='\0') return -1;
    else if(*p2=='\0' && *p1!='\0') return 1;
    else if(*p2=='\0' && *p1=='\0') return 0;
    char m1,m2;
    if(*p1>='a' && *p1<='z') m1=(char)(*p1-32);
    else m1=*p1;
    if(*p2>='a' && *p2<='z') m2=(char)(*p2-32);
    else m2=*p2;
    if(a[m1] > a[m2])
    {
        return 1;
    }
    else if(a[m1] < a[m2])
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int cmp(const void*_a,const void*_b)
{
    char* a=(char*)_a;
    char* b=(char*)_b;
    return strcmp1(a,b);
}
int main()
{
    char s[30];
    while(scanf("%s",s)!=EOF)
    {
        char x[110][25];
        int i;
        for(i=0;i<26;i++)
        {
            a[s[i]]=i;
        }
        int k=0;char c;
        while(scanf("%s",x[k])!=EOF)
        {
            k++;
            c=getchar();
            if(c=='\n') break;
        }
        qsort(x,k,sizeof(x[0]),cmp);
        for(int h=0;h<k-1;h++)
        {
            printf("%s ",x[h]);
        }
        printf("%s\n",x[k-1]);
    }
    return 0;
}
