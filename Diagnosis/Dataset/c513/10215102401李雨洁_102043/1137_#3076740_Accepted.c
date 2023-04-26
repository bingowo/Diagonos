#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(char s1[],char s2[])//正整数加法
{
    int  a[1001]= {0},b[1001]= {0},c[5000]= {0};//定义三个整形数组来储存数据
    int i,j,len,len1,len2;
    //scanf("%s %s",s1,s2);
    len1=strlen(s1);
    len2=strlen(s2);
    len=len1>len2?len1:len2;//求出两个字符串长度的大值
    for(i=len1-1,j=0; i>=0; i--)
    {
        a[j]=s1[i]-'0';
        j++;
    }//将字符数转化为整形数后倒序输入整形数组中.方便下面的进位运算
    for(i=len2-1,j=0; i>=0; i--)
    {
        b[j]=s2[i]-'0';
        j++;
    }
    for(i=0; i<=len; i++)
    {
        c[i]=c[i]+a[i]+b[i];
        if(c[i]>9)
        {
            c[i+1]++;
            c[i]=c[i]-10;//
        }
    }
    int flag=0;//设置一个标志用来判断0+0
    for(i=len; i>=0; i--)
    {
        if(c[i]!=0)//去除前缀多余的0
        {
            flag=1;
            for(j=i; j>=0; j--)
                printf("%d",c[j]);//将其倒叙输出
            break;
        }
    }
    if(flag==0)
        printf("0\n");
}

void sub(char a[],char b[])//正整数减法
{
    int s1[500]={0},s2[500]={0},s3[500];
   int m,n,len,i,flag=0;
        m=strlen(a);
        n=strlen(b);
        for(i=0;i<m;i++) s1[i]=a[m-i-1]-'0';
        for(i=0;i<n;i++) s2[i]=b[n-i-1]-'0';
        if(m>n)
        {
            len=m;flag=0;
            for(i=n;i<m;i++) s2[i]=0;
        }
        else if(m==n)
        {
            len=m;
            for(i=n-1;i>=0;i--)
            {
                if(s1[i]>s2[i])
                {
                    flag=0;break;
                }
                if(s1[i]<s2[i])
                {
                    flag=1;break;
                }
            }
        }
        else
        {
            len=n;flag=1;
            for(i=m;i<n;i++) s1[i]=0;
        }
        if(flag==0)
        {
            for(i=0;i<len;i++)
            {
                if(s1[i]>=s2[i]) s3[i]=s1[i]-s2[i];
                else
                {
                    s1[i]=s1[i]+10;
                    s1[i+1]=s1[i+1]-1;
                    s3[i]=s1[i]-s2[i];
                }
            }
        }
        if(flag==1)
        {
            for(i=0;i<len;i++)
            {
                if(s2[i]>=s1[i]) s3[i]=s2[i]-s1[i];
                else
                {
                    s2[i]=s2[i]+10;
                    s2[i+1]=s2[i+1]-1;
                    s3[i]=s2[i]-s1[i];
                }
            }
        }
        int k=0;
        for(i=0;i<len;i++)
        {
            if(s3[i]==0) k=0;
            else
            {
                k=1;break;
            }
        }
        if(k==0) printf("0\n");
        if(k!=0)
        {
            if(flag==0)
            {
                for(i=len-1;i>=0;i--)
                {
                    if(s3[i]!=0)
                    {
                        printf("%d",s3[i]);
                        i--;break;
                    }
                }
                for(;i>=0;i--)
                {
                    printf("%d",s3[i]);
                }
                printf("\n");
            }
            if(flag==1)
            {
                printf("-");
                for(i=len-1;i>=0;i--)
                {
                    if(s3[i]!=0)
                    {
                        printf("%d",s3[i]);
                        i--;break;
                    }
                }
                for(;i>=0;i--)
                {
                    printf("%d",s3[i]);
                }
                printf("\n");
            }
        }
}

int main()
{
    char s1[1001],s2[1001];
    char ss1[1001],ss2[1001];
    scanf("%s %s",s1,s2);
    if(s1[0]!='-'&&s2[0]!='-')
        add(s1,s2);
    else if(s1[0]=='-'&&s2[0]=='-')
    {
        for(int i=0;i<strlen(s1)+1;i++)
        {
            ss1[i]=s1[i+1];
        }
        for(int i=0;i<strlen(s2)+1;i++)
        {
            ss2[i]=s2[i+1];
        }
        printf("-");
        add(ss1,ss2);
    }
    else if(s1[0]!='-'&&s2[0]=='-')
    {
        for(int i=0;i<strlen(s2)+1;i++)
        {
            ss2[i]=s2[i+1];
        }
        sub(s1,ss2);
    }
    else if(s1[0]=='-'&&s2[0]!='-')
    {
        for(int i=0;i<strlen(s1)+1;i++)
        {
            ss1[i]=s1[i+1];
        }
        sub(s2,ss1);
    }
    return 0;
}

