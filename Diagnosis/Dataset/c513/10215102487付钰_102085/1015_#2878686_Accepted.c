#include<stdio.h>
#include<string.h>

int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        char input1[100]={'\0'},input2[100]={'\0'};
        scanf("%s %s",input1,input2);//输入两个素数进制的数
        int i,cnt1,cnt2,tmp,num1[30]={0},num2[30]={0};
        for(i=strlen(input1)-1,tmp=1,cnt1=0;i>=0;i--)//从素数进制最后一位开始循环
        {
            if(input1[i]==',')
            {
                tmp=1;
                cnt1++;
            }
            else
            {
                num1[cnt1]+=tmp*(input1[i]-'0');
                tmp*=10;
            }
        }
        for(i=strlen(input2)-1,tmp=1,cnt2=0;i>=0;i--)
        {
            if(input2[i]==',')
            {
                tmp=1;
                cnt2++;
            }
            else
            {
                num2[cnt2]+=tmp*(input2[i]-'0');
                tmp*=10;
            }
        }
        //将每位上的非负整数按位存放在两个整型数组中
        i=0;
        int carry=0,res[30]={0};
        while (i<=cnt1 || i<=cnt2 || carry!=0)
        {
            res[i]=num1[i]+num2[i]+carry;
            if(res[i]>=prime[i])
            {
                res[i]-=prime[i];
                carry=1;
            }
            else carry=0;
            i++;
        }
        printf("case #%d:\n",t);
        for(--i;i>0;i--) printf("%d,",res[i]);
        printf("%d\n",res[i]);
        t++;
    }
    return 0;
}