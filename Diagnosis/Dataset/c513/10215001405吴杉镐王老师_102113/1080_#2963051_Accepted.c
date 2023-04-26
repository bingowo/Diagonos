#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T;
char s[10005];

struct node{
    int num[1005],cnt;
}A,B;

int main()
{
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%s",s);
        B.cnt=A.cnt=0;
        
        //读入整型数组
        for(int i=0;s[i];i++)
            A.num[++A.cnt]=s[i]-'0';
        
        while(A.cnt>0)
        {
            if(A.num[A.cnt]%2) //是偶数（看末位）
                B.num[++B.cnt]=1;
            else
                B.num[++B.cnt]=0;
            //整体除以2的算法 进位的运算很关键！
            for(int i=1;i<=A.cnt;i++)
            {
                A.num[i+1]+=(A.num[i]%2)*10;
                A.num[i]/=2; //高位除以2，若为奇数则留给下一位
            }
            //高位被除为0后的解决方案
            if(A.num[1]==0)
            {
                for(int i=1;i<A.cnt;i++)
                    A.num[i]=A.num[i+1];
                A.cnt--;
            }
        }
        printf("case #%d:\n",c);
        A.num[A.cnt=1]=0; //清楚A.num[1]中的干扰元素 这时A.num的所有元素都是0
        //处理倒置
        for(int i=1;i<=B.cnt;i++)
        {
            for(int j=1;j<=A.cnt;j++)
                A.num[j]*=2; //就是对原先A.num中的所有元素乘2
            A.num[1]+=B.num[i]; //再加入权重更低的数
            //二进制的算法很重要！
            for(int j=1;j<A.cnt;j++)
            {
                A.num[j+1]+=A.num[j]/10;
                A.num[j]%=10;
            }
            if(A.num[A.cnt]>9)
            {
                A.num[A.cnt+1]=A.num[A.cnt]/10;
                A.num[A.cnt]%=10;
                A.cnt++;
            }
        }
        for(int i=A.cnt;i;i--)
            printf("%d",A.num[i]);
        puts("");
    }
    return 0;
}
