#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct{char c[11];} string;
double turn(char *c)
{
    double sum1=0,sum2=0,q=0;
    int i=0;
    while (c[i]&&c[i]!='.')
        sum1=sum1*10+c[i++];
    while (c[i++])
        sum2=sum2+c[i]/pow(10,--q);
    return sum1+sum2;
}
double change (string* s,int len)
{
    if (len==0) return 0;
    if (strcmp(s->c,"+")==0) return change(s+1,len-1)+change(s+2,len-2);
    if (strcmp(s->c,"-")==0) return change(s+1,len-1)-change(s+2,len-2);
    if (strcmp(s->c,"*")==0) return change(s+1,len-1)*change(s+2,len-2);
    if (strcmp(s->c,"/")==0) return change(s+1,len-1)/change(s+2,len-2);
    return turn(s->c);
}
int main ()
{
    int T;
    scanf ("%d",&T);
    for (int q=0;q<T;q++)
    {
        string s[101];
        int len=0;
        while (scanf("%s",s[len++].c));
        printf("case #%d:\n%f\n",q,change(s,len));
    }
    return 0;
}
