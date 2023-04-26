#include <stdio.h>
#include <string.h>
int main()
{
    char s[50];
    int len,T,m;
    double n;
    scanf("%d",&T);
    for(m =0;m<T;m++)
    {
        scanf("%s",s);
        n=0;
        len=strlen(s);
        int i;
        for(i=len-1;s[i]!='.';i--)
        {
            n/=(double)8.0;
            n+=(double)s[i]-'0';
        }
        n/=(double)8.0;
        printf("case #%d：\n%.45g \n",m,n);
    }
    return 0;
}