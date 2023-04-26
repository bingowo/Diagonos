#include<stdio.h>
#include<string.h>
#include<math.h>
void mul(int* ans,int a)
{
    int flag=0;
    for(int i=9999;i>=0;i--)
    {
        int temp=ans[i]*a;
        if(temp>=10)
        {
            ans[i]=temp%10+flag;
            flag=(temp+flag)/10;
        }
        else
        {
            ans[i]=temp+flag;
            flag=0;
        }
    }
}
int ans[10000]={0};
int main()
{
    char s[1000]={0};
    scanf("%s",s);
    ans[9999]=1;
    int len=strlen(s);
    if(len==1)
    {
        printf("1");
        return 0;
    }
    for(int i=0;i<len;i++)
    {
        if(i==0)
        {
            if(s[i]!=s[i+1]) mul(ans,2);
            //printf("%d\n",ans[9999]);
        }
        else if(i==len-1)
        {
            if(s[i]!=s[i-1]) mul(ans,2);
            //printf("111%d %d\n",ans[9998],ans[9999]);
        }
        else
        {
            if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
            {
                mul(ans,3);
                //printf("%d 222%d %d\n",i,ans[9998],ans[9999]);
                continue;
            }
            if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]==s[i+1])
            {
                mul(ans,2);
                //printf("333%d %d\n",ans[9998],ans[9999]);
                continue;
            }
            if(s[i]==s[i-1]&&s[i]!=s[i+1])
            {
                mul(ans,2);
                //printf("444%d %d\n",ans[9998],ans[9999]);
                continue;
            }
            if(s[i]!=s[i-1]&&s[i]==s[i+1])
            {
                mul(ans,2);
                //printf("555%d %d\n",ans[9998],ans[9999]);
                continue;
            }
           //printf("666%d %d\n",ans[9998],ans[9999]);
        }

        /*int flag=0;
        for(int i=0;i<10000;i++)
       {
        if(flag==0&&ans[i]==0) continue;
        if(flag==0&&ans[i]!=0)
        {
            printf("%d",ans[i]);
            flag=1;
            continue;
        }
        if(flag==1) printf("%d ",ans[i]);

        }*/

    }
    //printf("\n");
    int flag=0;
    for(int i=0;i<10000;i++)
    {
        if(flag==0&&ans[i]==0) continue;
        if(flag==0&&ans[i]!=0)
        {
            printf("%d",ans[i]);
            flag=1;
            continue;
        }
        if(flag==1) printf("%d",ans[i]);

    }
}
