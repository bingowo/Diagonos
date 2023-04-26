#include<stdio.h>
#include<string.h>
char in[101];
int ans[101];
int main()
{
    scanf("%s",in);
    int i,len=strlen(in),k=1,sum=0,j;
    for(i=1;i<=len;i++)
    {
        ans[i]=in[i-1]-'0';
    }
    while(k!=0)
    {
        if(k==1)
        {
            ans[len]++;
        }
        k=0;
        for(i=0;i<=len;i++)
        {
            if(ans[i]!=9)
            {
                sum+=ans[i];
            }
            else
            {
                ans[i-1]++;
                for(j=i;j<=len;j++)
                {
                    ans[j]=0;
                }
                sum=0;
                k=2;
            }
        }
        if(sum%9==0&&k!=2)
        {
            k=1;
        }
    }
    if(ans[0]!=0)
    {
        printf("%d",ans[0]);
    }
    for(i=1;i<=len;i++)
    {
        printf("%d",ans[i]);
    }
    return 0;
}
