#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[61];
        scanf("%s",s);
        int flag[500];
        for(int m=0;m<500;m++)
        {
            flag[m]=-1;
        }
        int data[500];
        int a=1;
        int num=0;
        long long  ans=0;
        for(int j=0;j<strlen(s);j++)
        {
            if(flag[s[j]]==-1&&a==1)
            {
                data[s[j]]=a;
                flag[s[j]]=0;
                a=0;
                num++;
            }
            else if(flag[s[j]]==-1&&a==0)
            {
                data[s[j]]=a;
                a=2;
                flag[s[j]]=0;
                num++;
            }
            else if(flag[s[j]]==-1&&a!=0&&a!=1)
            {
                data[s[j]]=a;
                a++;
                flag[s[j]]=0;
                num++;
            }
        }
        if(num==1)
        {
            num=2;
        }
        for(int j=0;j<strlen(s);j++)
        {
            ans=ans+data[s[j]];
            if(j!=strlen(s)-1)
            {
                ans=ans*num;
            }
        }
        printf("case #%d:\n%lld\n",i,ans);

    }
    return 0;
}
