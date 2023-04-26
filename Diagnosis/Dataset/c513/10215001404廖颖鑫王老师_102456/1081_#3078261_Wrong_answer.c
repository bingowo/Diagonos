#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int a,n;
        scanf("%d %d",&a,&n);
        int s[102]={0};
        s[0]=1;
        for(int r=0;r<n;r++)//每一次循环都乘上一次a
        {
            int num=0;//num=0一定要写在这里
            for(int j=0;j<100;j++)
            {
                s[j]=s[j]*a+num;//如果s[j]<10,直接记录即可
                num=0;//我也不知道这里。。。
                if(s[j]>9)
                {
                    num=s[j]/10;//num是进位的数字
                    s[r]=s[r]%10;
                }
            }
        }
        int t;
        for(t=99;t>-1;t--)
        {
            if(s[t]!=0)
            break;//t即为位数
        }
        for(int l=t;l>-1;l--)
        {
            printf("%d",s[l]);
        }
        printf("\n");
        return 0;
    }
}