#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double a[30];
char x[55];
int cmp(const void*_a,const void*_b)
{
    char* a=(char*)_a;
    char* b=(char*)_b;
    int m1,m2,m3,m4;
    if(*a>='a' && *a>='z')
    {
        m1=*a -'a';m3=2*m1;
    }
    else
    {
        m1=*a - 'A';m3=2*m1+1;
    }
    if(*b>='a' && *b<='z')
    {
        m2=*b - 'a';m4=2*m2;
    }
    else
    {
        m2=*b -'A';m4=2*m2+1;
    }
    if(fabs(a[m1]-a[m2])>1e-6)
        return (a[m1]>a[m2]?-1:1);
    else return(m2>m4 ? 1:-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    char s[110];
    char c='a';
    for(int i=0;i<=50;i+=2)
    {
        x[i]=(char)c;
        c++;
    }
    c='A';
    for(int i=1;i<=51;i+=2)
    {
        x[i]=(char)c;
        c++;
    }
    for(int i=0;i<T;i++)
    {
        for(int j=0;j<26;j++)
        {
            scanf("%lf",&a[j]);
        }
        gets(s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}
