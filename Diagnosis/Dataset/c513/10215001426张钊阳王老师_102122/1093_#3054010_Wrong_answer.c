#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char num[120];
    scanf("%s",num);
    int l=strlen(num);
    //需要先预处理
    int a1[120];
    int a[120];
    for(int k=0;k<l;k++)
    {
        a1[k]=num[k]-'0';
    }
    a1[l-1]++;
    for(int k=l-1;k>=1;k--)
    {
        if(a1[k]>=10) {a1[k]-=10;a1[k-1]++;}
    }

    if(a1[0]>=10) {
        a[0]=1;
        a1[0]-=10;
        for(int g=0;g<l;g++)
            a[g+1]=a1[g];
        l++;
    }
    else {
        for(int g=0;g<l;g++)
            a[g]=a1[g];
    }
    //测试
    //printf("%d\n",l);
    //for(int i=0;i<l;i++) printf("%d ",a[i]);
    //printf("\n");
    //第一种情况：如果有数码9
    int flag=0,set;
    for(int j=0;j<l;j++)
    {
        if(a[j]==9) {flag=1;set=j;break;}
    }

    if(flag==1)
    {
    while(flag==1)
    {
        if(set==0)
        {
            a[0]=1;
            for(int z=l;z>=1;z--) a[z]=0;
            l++;
        }
        else {
            a[set-1]++;
            for(int z=set;z<l;z++)
            {
                a[z]=0;
            }
        }
        flag=0;
        for(int j=0;j<l;j++)
        {
            if(a[j]==9) {flag=1;set=j;break;}
        }
    }
    int sum=0;
    for(int j=0;j<l;j++)
    {
        sum+=a[j];
    }
    while(sum%9==0)
    {
        a[l-1]++;
    }
    }

    else if(flag==0)
    {
        int sum=0;
        for(int j=0;j<l;j++)
        {
            sum+=a[j];
        }
        if(sum%9==0) a[l-1]++;
        else ;
    }
    //处理之后进位
    for(int g=l-1;g>=1;g--)
    {
        if(a[g]>=10) {a[g]-=10;a[g-1]++;}
    }
    int ans[120];
    if(a[0]>=10)
    {
        ans[0]=1;
        for(int t=0;t<l;t++)
        {
            ans[t+1]=a[t];
        }
        l++;
    }
    else {
        for(int t=0;t<l;t++)
        {
            ans[t]=a[t];
        }
    }
    for(int i=0;i<l;i++) printf("%d",a[i]);
    return 0;
}
