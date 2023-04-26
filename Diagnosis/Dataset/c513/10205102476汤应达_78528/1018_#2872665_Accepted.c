#include<stdio.h>
#include<string.h>
int prime[27]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2,1};

int read(char*num,int*data)
{
    int cnt=0,p=0,tmp=0;
    for(int i=0;i<=(int)strlen(num);i++)
    {
        if(num[i]==',' || i==(int)strlen(num))
        {
            while (p)
            {
                tmp=tmp*10+num[i-p]-'0';
                p--;
            }
            data[cnt++]=tmp;tmp=0;            
        }
        else p++;
    }
    return cnt;
}

int main()
{
    char num[100];scanf("%s",num);
    int data[25],cnt=read(num,data);
    int pow[100]={0},l=100,carry=0,p=26;    //记录位权
    int ans[100]={0},start=0;   //记录答案
    //pow数组记录位权
    pow[l-1]=1;
    for(int i=cnt-1;i>=0;i--)
    {
        //每次先计算位权
        for(int j=l-1;j>=0;j--)
        {
            pow[j]=carry+pow[j]*prime[p];
            if(pow[j]>=10)
            {
                carry=pow[j]/10;
                pow[j]%=10;
            }
            else carry=0;
        }
        p--;carry=0;
        for(int j=l-1;j>=0;j--)
        {
            ans[j]+=(carry+pow[j]*data[i]);
            if(ans[j]>=0)
            {
                carry=ans[j]/10;
                ans[j]%=10;
            }
            else carry=0;
        }
    }
    while(ans[start]==0 && start<l-1) start++;
    for(;start<l;start++) printf("%d",ans[start]);

    return 0;
}