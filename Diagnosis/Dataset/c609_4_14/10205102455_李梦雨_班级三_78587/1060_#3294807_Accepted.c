#include <stdio.h>
#define N 100

int main()
{
    char s[N+1],t[2*N+1],*ps=s,*pt=t,c;
    int cnt,i,j;
    struct {char letter;int n;} a[N+1];
    scanf("%s",s);
    a[cnt=0].letter=*ps++,a[cnt].n=1;
    while(c=*ps++)
        if(c==a[cnt].letter) a[cnt].n++;
        else a[++cnt].letter=c,a[cnt].n=1;
    a[++cnt].letter=c;
    for(i=0;i<cnt;i++)
    {
        for(j=0;j<a[i].n*(1+(a[i].letter<a[i+1].letter));j++)
        {
            *pt++=a[i].letter;
        }
    }
    *pt=0;
    printf("%s\n",t);
    return 0;
}