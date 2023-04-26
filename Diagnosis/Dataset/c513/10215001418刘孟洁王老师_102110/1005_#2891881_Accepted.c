#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000

int main()
{
    int n,i,num,sum,j,k,x;
    char s[N],t[N];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        k=0;
        scanf("%s",s);
        memset(t,0,sizeof(t));
        for(j=strlen(s)-1;j>1;j--)
        {
            num=s[j]-'0';
            for(x=0;x<k||num!=0;x++)
            {
                sum=num*10+(x<k?t[x]-'0':0);/*确定前一步是否有商，有商需要加上继续除*/
                t[x]=sum/8+'0';
                num=sum%8;
            }/*类比：0.75=0.((50/10+70)/10)*/
            k=x;
        }
        printf("case #%d:\n0.%s\n",i,t);
    }
    return 0;
}
