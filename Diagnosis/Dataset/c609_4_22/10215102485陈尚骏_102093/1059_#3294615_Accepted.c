#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int cmp(const void*a,const void*b)
{
    char*a1=(char*)a;
    char*b1=(char*)b;
    int sgn1=1,sgn2=1;
    if(*a1=='-')
    {
        sgn1=-1;
        a1++;
    }
    else if(*a1=='+') a1++;
    if(*b1=='-')
    {
        sgn2=-1;
        b1++;
    }
    else if(*b1=='+') b1++;
    if(sgn1!=sgn2) return sgn1-sgn2;
    char*a2,*b2;
    for(a2=a1;*a2&&*a2!='.';a2++);
    for(b2=b1;*b2&&*b2!='.';b2++);
    int len1=a2-a1,len2=b2-b1;
    if(len1!=len2) return sgn1*(len1-len2);
    return sgn1*strcmp(a1,b1);
}

int main()
{
    char s[100][101];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%s",s[i]);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;++i)
    {
        printf("%s\n",s[i]);
    }
    return 0;
}
