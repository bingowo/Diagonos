#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000000007


int main()
{
    long long ans[1000]={0};
    int cnt[1200];
    for(int i=0;i<1200;i++)
    {
        cnt[i]=1;
    }
    char s[1200];
    memset(s,'\0',1200);
    scanf("%s",s);
    int l=strlen(s);
    if(l==1) printf("1");
    else {
         for(int i=0;i<l;i++)
    {
        if(i==0)
        {
            if(s[i]!=s[i+1])
            {
                cnt[0]++;
            }
            else ;
        }
        else if(i==l-1)
        {
            if(s[i]!=s[i-1])
            {
                cnt[l-1]++;
            }
            else ;
        }
        else
        {
            if(s[i]!=s[i-1])
            {
                cnt[i]++;
            }
            if(s[i]!=s[i+1])
            {
                cnt[i]++;
            }

            if(cnt[i]==3&&s[i-1]==s[i+1]) cnt[i]--;
        }
    }//于是得到一个cnt数组 将l个数组中的元素相乘


    ans[0]=cnt[0];

    int l0=1;
    for(int i=1;i<l;i++)
    {
        int temp=cnt[i];
        if(temp==1) continue;
        else
        {
            for(int j=l0-1;j>=0;j--)
            {
                ans[j]*=temp;
            }
            for(int t=l0-1;t>=1;t--)
            {
                if(ans[t]>=10)
                {
                    ans[t-1]=ans[t-1]+ans[t]/10;
                    ans[t]%=10;
                }
            }
            if(ans[0]>=10)
            {
                for(int z=l0-1;z>=1;z--)
                {
                    ans[z+1]=ans[z];
                }
                int g=ans[0];
                ans[1]=ans[0]%10;
                ans[0]=g/10;
                l0++;//l0表示答案数组的长度
            }
            else ;
        }
        //for(int t=0;t<l0;t++) printf("%d",ans[t]);
        //printf("\n");
    }



    //最后要对数据做取模处理
    //可以先试一下long long

    long long int sum=0;
    for(int i=0;i<l0;i++)
        sum=sum*10+ans[i];

    long long x;
    x=sum%N;
    printf("%lld",x);
    }

    return 0;
}
