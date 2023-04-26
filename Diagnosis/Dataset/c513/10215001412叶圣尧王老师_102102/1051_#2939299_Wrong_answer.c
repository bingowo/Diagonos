#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char prime[63];int i;
    for(i=0;i<26;i++)prime[i]='A'+i;
    for(i=26;i<52;i++)prime[i]='a'+i-26;
    for(i=52;i<62;i++)prime[i]=i-52;
    prime[62]='+';prime[63]='/';
    int T,j=0;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        char s[101];scanf("%s",s);
        int a[900]={0},b[250]={0},d;
        for(i=0;i<strlen(s);i++)
        {
            d=s[i];
            for(;d>0;d/=2,j++)
                a[j]=d%2;
        }
        while(j%6!=0){a[j]=0;j++;}
        int k=0,len=j;
        for(j=0;j<len;j++)
        {
            b[k]=b[k]*2+a[j];
            if((j+1)%4==0)k++;
        }
        for(j=0;j<k;j++)
            printf("%c",prime[b[j]]);
        for(j=0;j<4-k;j++)printf("=");
        printf("\n");
        
    }
}