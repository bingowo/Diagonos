#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char prime[64];int i;
    for(i=0;i<26;i++)prime[i]='A'+i;
    for(i=26;i<52;i++)prime[i]='a'+i-26;
    for(i=52;i<62;i++)prime[i]=i-52+'0';
    prime[62]='+';prime[63]='/';
    int T,j=0;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        char s[101];scanf("%s",s);
        int a[900]={0},a1[8]={0},b[250]={0},d,len;
        for(i=0;i<strlen(s);i++)
        {
            d=s[i];
            for(j=0;d>0;d/=2,j++)
             a1[j]=d%2;
             int e=0;
            for(d=(i+1)*8-1;d>=(i+1)*8-j;d--)a[d]=a1[e++];
        }len=8*strlen(s);
        while(len%6!=0)len++;
        int k=0;
        for(j=0;j<len;j++)
        {
            b[k]=b[k]*2+a[j];
            if((j+1)%6==0)k++;
        }
        for(j=0;j<k;j++)
            printf("%c",prime[b[j]]);
        while(k%4!=0){printf("=");k++;}
        printf("\n");

    }
}
