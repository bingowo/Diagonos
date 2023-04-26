#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,k,t,l,tmp,len1=1,m=0;
    int num[1007];
    memset(num,0,sizeof(num));//记得清零
    num[0]=1;
    char s[1007];
    scanf("%s",s);
    l=strlen(s);
    if(l==1) printf("1");
    else if(l==2)
    {
        if(s[0]==s[1]) printf("1");
        else printf("4");
    }
    else
    {
        if(s[0]!=s[1]) num[0]=2;
        for(i=1;i<=l-1;i++)
        {
            if(i==l-1&&s[i]!=s[i-1])
            {
                m=0;
                for(j=0;j<len1;j++)
                {
                    tmp=num[j]*2+m;
                    num[j]=tmp%10;
                    m=tmp/10;
                }
                while(m)
                {
                    num[len1++]=m%10;
                    m/=10;
                }
            }
            else if((s[i]==s[i-1]&&s[i]!=s[i+1])||(s[i]!=s[i-1]&&s[i]==s[i+1])||(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]==s[i+1]))
            {
                if(i==l-1) continue;
                else
                {
                m=0;
                for(j=0;j<len1;j++)
                {
                    tmp=num[j]*2+m;
                    num[j]=tmp%10;
                    m=tmp/10;
                }
                while(m)
                {
                    num[len1++]=m%10;
                    m/=10;
                }
                }
            }
            else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
            {
                m=0;
                for(j=0;j<len1;j++)
                {
                    tmp=num[j]*3+m;
                    num[j]=tmp%10;
                    m=tmp/10;
                }
                while(m)
                {
                    num[len1++]=m%10;
                    m/=10;
                }
            }
        }

    }
    for(i=len1-1;i>=0;i--) printf("%d",num[i]);//别忘记倒过来
    return 0;
}
