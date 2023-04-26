#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sub(char a[],char b[])//大整数减法
{
    int s1[500]={0},s2[500]={0},s3[500];
    //s3存结果
    int len,flag=0;//flag为结果符号标记
    //浮点数转整数，倒着存储
    int m=strlen(a),n=strlen(b);
    for(int i=0;i<m;i++)
        s1[i]=a[m-i-1]-'0';
    for(int i=0;i<n;i++)
        s2[i]=b[n-i-1]-'0';

    if(m>n)
    {
        len=m;
        flag=0;//正数结果
        for(int i=n;i<m;i++)
            s2[i]=0;
    }
    else if(m==n)
    {
        len=m;
        for(int i=n-1;i>=0;i--)
        {
            if(s1[i]>s2[i])
            {
                flag=0;
                break;
            }
            if(s1[i]<s2[i])
            {
                flag=1;
                break;
            }
        }
    }
    else
    {
        len=n;
        flag=1;//负数结果
        for(int i=m;i<n;i++)
            s1[i]=0;
    }

    if(flag==0)//结果为正
    {
        for(int i=0;i<len;i++)
        {
            if(s1[i]>=s2[i])
                s3[i]=s1[i]-s2[i];
            else
            {
                s1[i]+=+10;
                s1[i+1]-=1;
                s3[i]=s1[i]-s2[i];
            }
        }
    }
    if(flag==1)//结果为负
    {
        for(int i=0;i<len;i++)
        {
            if(s2[i]>=s1[i])
                s3[i]=s2[i]-s1[i];
            else
            {
                s2[i]+=10;
                s2[i+1]-=1;
                s3[i]=s2[i]-s1[i];
            }
        }
    }
    int k=0;
    for(int i=0;i<len;i++)
    {
        if(s3[i]==0) k=0;
        else
        {
            k=1;
            break;
        }
    }
    if(k==0)//s3为0
        printf("0\n");
    else
    {
        if(flag==0)//正数
        {
            int i;
            for(i=len-1;i>=0;i--)
            {
                if(s3[i]!=0)
                {
                    printf("%d",s3[i]);
                    i--;
                    break;
                }
            }
            for(;i>=0;i--)
                printf("%d",s3[i]);
            printf("\n");
        }
        else//负数
        {
            int i;
            printf("-");
            for(i=len-1;i>=0;i--)
            {
                if(s3[i]!=0)
                {
                    printf("%d",s3[i]);
                    i--;
                    break;
                }
            }
            for(;i>=0;i--)
                printf("%d",s3[i]);
            printf("\n");
        }
    }
}
int main()
{
    char a[500],b[500];
    while(~scanf("%s %s",a,b))
        sub(a,b);
    return 0;
}
