#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int cmpN(const void *a,const void *b)
{
    char *a1=(char*)a,*b1=(char*)b;
    int i=34;
    for (i;(a1[i]=='\0')&&(b1[i]=='\0');i++)
    {
        if (a1[i]!=b1[i]) return a1[i]-b1[i];
    }
    return a1[i]-b1[i];
}

int cmpT(const void *a,const void *b)
{
    char *a1=(char*)a,*b1=(char*)b;
    for (int i=0;i<16;i++)
    {
        if (a1[i]!=b1[i]) return a1[i]-b1[i];
    }
    return cmpN (a,b);
}
int cmpS(const void *a,const void *b)
{
    char *a1=(char*)a,*b1=(char*)b;
    int i=16,j=16,suma=0,sumb=0;
    while (a1[i++]==0);while (b1[j++]==0);
    i-=1;j-=1;
    for (i;i<=33;i++) suma=suma*10+a1[i];
    for (j;j<=33;j++) sumb=sumb*10+b1[j];
    if (suma!=sumb) return suma-sumb;
    return cmpN (a,b);
}
int main()
{
    int n;
    while(1)
    {
        scanf ("%d",&n);
        if (n==0) break;
        for(int i=0;i<n;i++)
        {
            char s[100][50],question[11];
            for (int j=0;j<n;j++)
            {
                gets(s[j]);
            }
            scanf("%s",question);
            if (question[6]=='N') qsort(s,n,sizeof(s[0]),cmpN);
            else if (question[6]=='S') qsort(s,n,sizeof(s[0]),cmpS);
            else if (question[6]=='T') qsort(s,n,sizeof(s[0]),cmpT);
            for (int j=0;j<n;j++) printf ("%s\n",s[j]);
        }
    }
    return 0;
}
