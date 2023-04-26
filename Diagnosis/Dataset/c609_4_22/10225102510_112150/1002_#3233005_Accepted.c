#include <stdio.h>
#include <stdlib.h>
#define N 100
int A(char *s,int j)
{
    int v=1,d=1,c=1;
    for(int n=0;n<j;n++)
    {
        if(s[n]!=s[n+1])
        {
            v++;
        }
        d=v>d?v:d;
        if(s[n]==s[n+1])
        {
            v=1;
        }
        c=v>d?v:d;
    }
    return c;
}
int main()
{
    int T,i=0,j=0;
    int a;
    char s[N];
    scanf("%d",&T);
    while(i<T)
    {
        scanf("%d",&a);
        for(j=0;a!=0;j++)
        {
            s[j]='0'+a%2;
            a=a/2;
        }
        j--;
        printf("case #%d:\n%d\n",i,A(s,j));
        i++;
    }
    return 0;
}

