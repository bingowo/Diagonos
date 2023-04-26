#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count(char a)
{
    int aa=(int)a;
    int cnt=0;
    for (int i=0;i<8;i++)
    {
        cnt=cnt+aa%2;
        aa=aa>>1;
    }
    return cnt;
}

int gcd(int m,int n)
{
    if (n==0) return m;
    else return gcd(n,m%n);
}

int mgetline(char s[],int lim)
{
    int c,i;
    i=0;
    while ((c=getchar())!=EOF && c!='\n' && i<lim-1)
        s[i++]=c;
    if (c==EOF && i==0)
        return -1;
    s[i]='\0';
    return i;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for (int i=0;i<n;i++)
    {
        char s[121]={0};
        int a=mgetline(s,121);
        int c=0,j;
        for (j=0;j<strlen(s);j++)
        {
            c=c+count(s[j]);
        }
        int m=8*strlen(s);

        printf("%d/%d\n",c/gcd(m,c),m/gcd(m,c));
    }
    return 0;
}
