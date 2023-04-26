#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 51
#define M 153

int main()
{
    int n,i,num,sum,j,k=0,x;char s[N],t[M];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        memset(t,0,sizeof(t));
        for(j=strlen(s)-1;j>1;j--)
        {
            num=s[j]-'0';
            for(x=0;x<k||num!=0;x++)
            {
                sum=num*10+(x<k?t[x]-'0':0);
                t[x]=sum/8+'0';
                num=sum%8;
            }
            k=x;
        }
        printf("case #%d:\n0.%s\n",i,t);
    }
    return 0;
}
