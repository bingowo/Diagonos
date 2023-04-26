#include<stdio.h>
#include<string.h>
int main()
{
    char S[101];
    scanf("%s",S);
    int i,lenth=0,ans=0,k=0;
    for(i=0;i<strlen(S);i++)
    {
        if(k==0)
        {
            if(S[i]>='1'&&S[i]<='9')
            {
                k=1;
                lenth++;
            }
        }
        else
        {
            if(S[i]<'0'||S[i]>'9')
            {
                k=0;
                if(lenth>ans)
                {
                    ans=lenth;
                }
                lenth=0;
            }
            else
            {
                lenth++;
            }
        }
    }
    if(lenth>ans)
    {
        ans=lenth;
    }
    printf("%d",ans);
    return 0;
}