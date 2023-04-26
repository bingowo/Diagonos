#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[100000]={0};
    int ans[100000]={0};
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        ans[i]=s[len-1-i]-'0';
    }
    ans[0]++;

    /*for(int i=len-1;i>=0;i--)
    {
        printf("%d",ans[i]);
    }
    printf("\n");*/

    for(int i=0;i<len;i++)
    {
        if(ans[i]>=10)
        {
            int temp=ans[i];
            ans[i]-=10;
            ans[i+1]++;
        }
    }

    while(1)
    {
        int temp=0;
        for(int i=0;i<len;i++)
        {
            if(i!=len-1&&ans[i]>=10)
            {
                int temp=ans[i];
                ans[i]-=10;
                ans[i+1]++;
            }
            if(ans[len]>0) len++;
        }

        /*for(int i=len-1;i>=0;i--)
        {
            printf("%d",ans[i]);
        }
        printf("\n");*/

        int flag=0;
        for(int i=0;i<len;i++)
        {
            if(ans[i]==9)
            {
                ans[0]++;
                flag=1;
                break;
            }
        }
        if(flag==1) continue;

        for(int i=0;i<len;i++)
        {
            temp+=ans[i];
        }
        if(temp%9==0)
        {
            ans[0]++;
            continue;
        }
        else break;
    }

    for(int i=0;i<len;i++)
    {
        if(i!=len-1&&ans[i]>=10)
        {
            int temp=ans[i];
            ans[i]-=10;
            ans[i+1]++;
        }
        if(ans[len]>0) len++;
    }

    for(int i=len-1;i>=0;i--)
    {
        printf("%d",ans[i]);
    }


}
