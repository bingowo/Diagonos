#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        char s[61];
        scanf("%s",s);
        int count=1;
        for(int j=1; s[j]; j++)//计算字符串中不同的字符共有多少个，即为几进制
        {
            int m=0;
            for(int z=0; z<j; z++)
            {
                if(s[j]==s[z])
                    break;
                else
                    m++;
            }
            if(m==j)
                count++;
        }
        long long int n=0;
        int a[61],q=2;
        a[0]=1;
        for(int j=1; s[j]; j++)//将字符串转换为count进制下的数组
        {
            int m=0,p=0;
            for(int z=0; z<j; z++)
            {
                if(s[j]==s[z])
                {
                    a[j]=a[z];
                    break;
                }
                else
                    m++;
                if(a[z]==1)
                    p++;
            }
            if(m==j&&m==p)
                a[j]=0;
            else if(m==j&&m!=p)
                a[j]=q++;
        }
        for(int j=0; s[j]; j++)//计算最小整数值
            n=n*count+a[j];
        printf("case #%d:\n%d\n",i,n);
    }
    return 0;
}
