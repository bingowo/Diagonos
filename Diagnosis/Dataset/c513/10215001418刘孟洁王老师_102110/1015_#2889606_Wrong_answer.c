#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
int min(int m,int n)
{
    if(m>=n)return n;
else return m;
}
int main()
{
    int n,h,l,g,k,x,q,i,c,j,num,sum;
    int d[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    char s[N],t[N];
    scanf("%d",&n);
    for(c=0;c<n;c++)
    {
        int a[26]={0};
        int b[26]={0};
        int f[26]={0};
        scanf("%s%s",s,t);
        for(i=strlen(s)-1,j=25;i>=0;i-=2,j--)
        {
                num=s[i]-'0';
                if(isdigit(s[i-1]))
           {for(i-=1;isdigit(s[i]);i--)
                num=num+(s[i]-'0')*10;}
                i++;
            a[j]=num;
        }

        for(k=strlen(t)-1,x=25;k>=0;k-=2,x--)
        {
            sum=t[k]-'0';
            if(isdigit(t[k-1]))
            {for(k-=1;isdigit(t[k]);k--)
                sum=sum+(t[k]-'0')*10;}
                k++;
            b[x]=sum;
        }
            q=0;
             int w=min(x,j);
        for(j=25,x=25,l=25,h=25;l>=w;j--,x--,l--,h--)
        {
             g=a[j]+b[x]+q;
             if(g<d[l])f[h]=g,q=0;
             else {q=g/d[l];f[h]=g%d[l];}
             if(q==0&&g==0&&l==w)break;

         }
         printf("case #%d:\n",c);
         for(h+=1;h<26;h++)
            printf("%d%c",f[h],h==25?'\n':',');
    }
    return 0;
}
