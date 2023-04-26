#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

int main()
{
    int n,h,l,g,k,x,q,i,c,j;
    int d[26]={97,91,89,83,79,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    char s[N],t[N];
    scanf("%d",&n);
    for(c=0;c<n;c++)
    {
        int a[26]={0};
        int b[26]={0};
        int f[26]={0};
        scanf("%s%s",s,t);
        for(i=strlen(s)-1,j=25;i>=0;i-=2,j--)
             a[j]=s[i]-'0';
        for(k=strlen(t)-1,x=25;k>=0;k-=2,x--)
             b[x]=t[k]-'0';
             q=0;
        for(j=25,x=25,l=24,h=25;l>=k||l>=i;j--,x--,l--,h--)
        {
             g=a[j]+b[x]+q;
             if(g<d[l])f[h]=g,q=0;
             else {q=g/d[l];f[h]=g%d[l];}
         }
         printf("case #%d:\n",c);
         for(h+=2;h<26;h++)
            printf("%d%c",f[h],h==25?'\n':',');
    }
    return 0;
}
