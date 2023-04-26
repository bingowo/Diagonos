#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long int poww(int a,int b);
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char s[65];
        scanf("%s",s);
        int l=strlen(s);
        int digit,dic[128];//注意第一位不能为0
        for(int z=0;z<128;z++)
        {
            dic[z]=-1;
        }
        digit=1;
        for(int i=0;i<l;i++)
        {
            if(i==0) dic[s[i]]=1;
            else {
                if(dic[s[i]]==-1)
                {
                    if(digit==1)
                    {
                        dic[s[i]]=0;
                        digit++;
                    }
                    else {
                        dic[s[i]]=digit;
                        digit++;
                    }
                }
                else{
                    ;
                }
            }
        }
        printf("%d",digit);
        //digit表示进制数
        if(digit==1) digit=2;
        long long int ans=0;
        for(int t=0;t<l;t++)
        {
            ans+=dic[s[t]]*pow(digit,l-t-1);
        }
        printf("case #%d:\n",t);
        printf("%lld\n",ans);
    }
    return 0;
}

long long int poww(int a,int b)
{
    long long int ans=1;
    for(int i=0;i<b;i++)
    {
        ans*=a;
    }
    return ans;
}
