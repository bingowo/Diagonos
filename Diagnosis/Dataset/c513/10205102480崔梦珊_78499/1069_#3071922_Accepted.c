#include<stdio.h>
#include<string.h>
#include<math.h>


int main()
{
    char s[11]={0};
    scanf("%s",s);
    int ans[11]={0};
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        ans[11-len+i]=s[i]-'0';
    }
    int num=0;
    int flag=0;
    while(flag==0)
    {
        int temp[11]={0};
        for(int i=0;i<len;i++)
        {
            temp[11-len+i]=ans[10-i];

        }
        /*for(int i=0;i<11;i++)
        {
            printf("%d",temp[i]);
        }*/
        for(int i=10;i>=0;i--)
        {
            int te=ans[i]+temp[i];
            if(te>=10)
            {
                ans[i-1]++;
                ans[i]=te-10;
            }
            else
            {
                ans[i]=te;
            }
        }
        /*for(int i=0;i<11;i++)
        {
            printf("%d",ans[i]);
        }
        printf("\n");*/
        num++;
        len=0;
        for(int i=0;i<=10;i++)
        {
            if(len!=0) len++;
            if(len==0&&ans[i]==0) continue;
            if(len==0&&ans[i]!=0) len++;
        }
        /*printf("%d\n",len);*/
        int flagg=0;
        if(len%2==0)
        {
            for(int i=0;i<len/2;i++)
            {
                if(ans[10-len/2-i]==ans[11-len/2+i])
                {
                    flagg++;
                }
            }
        }
        if(len%2==1)
        {
            for(int i=0;i<len/2;i++)
            {
                if(ans[9-len/2-i]==ans[11-len/2+i])
                {
                    flagg++;
                }
            }
        }
        if(flagg==len/2)
        {
            flag=1;
        }
    }
    printf("%d ",num);
    int sign=0;
    for(int i=0;i<=10;i++)
    {
        if(sign!=0) printf("%d",ans[i]);
        if(sign==0&&ans[i]==0) continue;
        if(sign==0&&ans[i]!=0)
        {
            printf("%d",ans[i]);
            sign++;
        }
    }
}
