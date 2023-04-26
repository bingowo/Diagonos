#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char s[10005];
int num[10005],cnt=0,l;
int main() {
    scanf("%s",s);
    l=strlen(s);
    for(int i=1;i<=10000;i++)
        num[i]=0;
    for(int i=l-1;i>=0;i--)
        num[++cnt]=s[i]-'0';
    num[1]++;
    for(int i=1;i<=cnt;i++)
    {
        num[i+1]+=num[i]/10;
        num[i]%=10;
    }
    if(num[cnt+1]>0)
        cnt++;   //模拟进位
    for(int i=cnt;i;i--){
        if(num[i]==9)
        {
            int j;
            for(j=i;j;j--)
                if(num[j]!=9)
                    break;  //找连续的9
            num[++j]++; //给最小位的9加1（理解!）
            for(int k=j;k<=cnt;k++)
            {
                if(num[k]==9)
                    num[k]++;
                num[k+1]+=num[k]/10;
                num[k]%=10;
            }
            if(num[cnt+1]>0)
                cnt++;
            for(int k=j-1;k;k--)
                num[k]=0; //低位就重新变成0，可以用四舍五入理解
            break; //故有9就会break
        } //算法大概是，从高位算起，第一个出现9的，代表低位再改变也没用，因此
          //改变最高位的9
    }
    int res=0;
    for(int i=1;i<=cnt;i++)
        res+=num[i]; //被9整除数的特征
    if(res%9==0){
        num[1]++;
        if(num[1]==9)
        {
            for(int j=1;j<=cnt;j++)
            {
                if(num[j]==9)
                    num[j]++;
                num[j+1]+=num[j]/10;
                num[j]%=10;
            }
            if(num[cnt+1]>0)
                cnt++;
            res=0;
            for(int i=1;i<=cnt;i++)
                res+=num[i];
            if(res%9==0)
                num[1]++;
        }
    }
    for(int i=cnt;i;i--) printf("%d",num[i]);
    return 0;
}
