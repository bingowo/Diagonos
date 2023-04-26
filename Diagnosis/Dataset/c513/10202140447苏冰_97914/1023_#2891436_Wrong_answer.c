#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int strnumcmp(const char* p1,const char* p2)
{
    while(*p1==*p2 && !isdigit(*p1) && !isdigit(*p2))
    {
        p1++;p2++;
    }
    int n1=0,n2=0;
    if(!isdigit(*p1) && !isdigit(*p2))
    {
        return (*p1 - *p2);
    }
    else if(isdigit(*p1) && isdigit(*p2))
    {
        while(isdigit(*p1))
        {
            n1=n1*10+(*p1-'0');
            p1++;
        }
        while(isdigit(*p2))
        {
            n2=n2*10+(*p2 - '0');
            p2++;
        }
        return (n1-n2);
    }
    else if(!isdigit(*p1) && isdigit(*p2))
    {
        return -1;
    }
    else if(isdigit(*p1) && !isdigit(*p2))
    {
        return 1;
    }
}
int cmp(const void*_a,const void*_b)
{
    char* a=(char*)_a;
    char* b=(char*)_b;
    return strnumcmp(a,b);
}
int main()
{
    char s[110][35];
    int n=0;
    while(scanf("%s",s[n])!=EOF)
    {
        n++;
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s ",s[i]);
    }
    return 0;
}

