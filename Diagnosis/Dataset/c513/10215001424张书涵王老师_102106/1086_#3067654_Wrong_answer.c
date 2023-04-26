#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char*s)
{
    int i,j;
    char c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

int main()
{
    char s1[1000]={0},s2[1000]={0},s[1000]={0};
    int c[1000]={0},k=0;
    int N,zhengshu_num1=0,zhengshu_num2=0,xiaoshu_num1=0,xiaoshu_num2=0;
    scanf("%s %s %d",s1,s2,&N);
    int i,j,lenth1,lenth2,lenth;
    lenth1=strlen(s1);lenth2=strlen(s2);
    if(s1[0]=='.')
    {
        for(i=lenth1;i>0;i--)
            s1[i]=s1[i-1];
        s1[i]='0';
        lenth1++;
    }
    if(s2[0]=='.')
    {
        for(i=lenth2;i>0;i--)
            s2[i]=s2[i-1];
        s2[i]='0';
        lenth2++;
    }
    for(i=0;i<lenth1;i++)
    {
        if(s1[i]=='.'&&s1[i+1]==0)
        {
            s1[i+1]='0';
            lenth1++;
        }
    }
    for(i=0;i<lenth2;i++)
    {
        if(s2[i]=='.'&&s2[i+1]==0)
        {
            s2[i+1]='0';
            lenth2++;
        }
    }
    for(i=0;s1[i];i++)
    {
        if(s1[i]=='.')
        {
            for(i=i+1;s1[i];i++)
                xiaoshu_num1++;
            break;
        }
        zhengshu_num1++;
    }
    for(i=0;s2[i];i++)
    {
        if(s2[i]=='.')
        {
            for(i=i+1;s2[i];i++)
                xiaoshu_num2++;
            break;
        }
        zhengshu_num2++;
    }
    if(xiaoshu_num1>xiaoshu_num2)
    {
        if(xiaoshu_num2==0)
        {
            s2[zhengshu_num2]='.';
            for(i=zhengshu_num2+1;i<(zhengshu_num2+xiaoshu_num1-xiaoshu_num2+1);i++)
                s2[i]='0';
        }
        else
        {
            for(i=lenth2;i<(lenth2+xiaoshu_num1-xiaoshu_num2);i++)
                s2[i]='0';
        }
    }
    if(xiaoshu_num1<xiaoshu_num2)
    {
        if(xiaoshu_num1==0)
        {
            s1[zhengshu_num1]='.';
            for(i=zhengshu_num1+1;i<(zhengshu_num1+xiaoshu_num2-xiaoshu_num1+1);i++)
                s1[i]='0';
        }
        else
        {
            for(i=lenth1;i<(lenth1+xiaoshu_num2-xiaoshu_num1);i++)
                s1[i]='0';
        }
    }
    reverse(s1);reverse(s2);
    lenth1=strlen(s1);lenth2=strlen(s2);
    if(zhengshu_num1>zhengshu_num2)//整数1个数大于整数2个数
    {
        for(i=lenth2;i<(lenth2+zhengshu_num1-zhengshu_num2);i++)
            s2[i]='0';
        lenth1=strlen(s1);
        for(i=0;i<lenth1;i++)
        {
            if(s1[i]=='.'||s2[i]=='.')
                c[i]=100;
            else
                c[i]=s1[i]-s2[i];
        }
        for(i=0;i<lenth1;i++)
        {
            if(c[i]<0)
            {
                if(c[i+1]==100)
                {
                    c[i]=c[i]+10;
                    c[i+2]=c[i+2]-1;
                }
                else
                {
                    c[i]=c[i]+10;
                    c[i+1]--;
                }
            }
        }
        lenth=lenth1;
        for(i=lenth1-1;i>=0;i--)
        {
            if(c[i]==0&&c[i-1]!=100)
                lenth--;
            break;
        }
        for(i=0;i<lenth;i++)
        {
            if(c[i]==100)
                s[i]='.';
            else
                s[i]=c[i]+'0';
        }
        reverse(s);//计算出最后相减得到的s
    }
    else
    {
        if(zhengshu_num1<zhengshu_num2)//整数1个数小于整数2个数
        {
            k=-1;
            for(i=lenth1;i<(lenth1+zhengshu_num2-zhengshu_num1);i++)
                s1[i]='0';
            lenth2=strlen(s2);
            for(i=0;i<lenth2;i++)
            {
                if(s2[i]=='.')
                    c[i]=100;
                else
                    c[i]=s2[i]=s1[i];
            }
            for(i=0;i<lenth1;i++)
            {
                if(c[i]<0)
                {
                    if(c[i+1]==100)
                    {
                        c[i]=c[i]+10;
                        c[i+2]--;
                    }
                    else
                    {
                        c[i]=c[i]+10;
                        c[i+1]--;
                    }
                }
            }
            lenth=lenth2;
            for(i=lenth2-1;i>=0;i--)
            {
                if(c[i]==0&&c[i-1]!=100)
                    lenth--;
                break;
            }
            for(i=0;i<lenth;i++)
            {
                if(c[i]==100)
                    s[i]='.';
                else
                    s[i]=c[i]+'0';
            }
            reverse(s);
        }
        else//两个数整数部分个数相同
        {
            reverse(s1);reverse(s2);
            for(j=0;j<lenth1;j++)
            {
                if(s1[j]>s2[j])
                {
                    reverse(s1);reverse(s2);
                    lenth1=strlen(s1);
                    for(i=0;i<lenth1;i++)
                    {
                        if(s1[i]=='.')
                            c[i]=100;
                        else
                            c[i]=s1[i]-s2[i];
                    }
                    for(i=0;i<lenth1;i++)
                    {
                        if(c[i]<0)
                        {
                            if(c[i+1]==100)
                            {
                                c[i]=c[i]+10;
                                c[i+2]=c[i+2]-1;
                            }
                            else
                            {
                                c[i]=c[i]+10;
                                c[i+1]--;
                            }
                        }
                    }
                    lenth=lenth1;
                    for(i=lenth1-1;i>=0;i--)
                    {
                        if(c[i]==0&&c[i-1]!=100)
                        lenth--;
                        break;
                    }
                    for(i=0;i<lenth;i++)
                    {
                        if(c[i]==100)
                            s[i]='.';
                        else
                            s[i]=c[i]+'0';
                    }
                    reverse(s);
                    break;
                }
                else
                {
                    if(s1[j]<s2[j])
                    {
                        reverse(s1);reverse(s2);
                        k=-1;
                        lenth2=strlen(s2);
                        for(i=0;i<lenth2;i++)
                        {
                            if(s2[i]=='.')
                                c[i]=100;
                            else
                                c[i]=s2[i]-s1[i];
                        }
                        for(i=0;i<lenth1;i++)
                        {
                            if(c[i]<0)
                            {
                                if(c[i+1]==100)
                                {
                                    c[i]=c[i]+10;
                                    c[i+2]--;
                                }
                                else
                                {
                                    c[i]=c[i]+10;
                                    c[i+1]--;
                                }
                            }
                        }
                        lenth=lenth2;
                        for(i=lenth2-1;i>=0;i--)
                        {
                            if(c[i]==0&&c[i-1]!=100)
                            lenth--;
                            break;
                        }
                        for(i=0;i<lenth;i++)
                        {
                            if(c[i]==100)
                                s[i]='.';
                            else
                                s[i]=c[i]+'0';
                        }
                        reverse(s);
                        break;
                    }
                }
            }
            if(j==lenth1)
                s[0]='0';
        }
    }
    int p;
    if(k==-1)
    printf("-");
    int c1[1000]={0};
    for(i=0;s[i];i++)
    {
        if(s[i]=='.')
        {
            c1[i]=100;
            p=i+1;
            for(i=p;i<(p+N);i++)
            {
                if(s[i]==0)
                    c1[i]=0;
                else
                    c1[i]=s[i]-'0';
            }
            if(s[i]>'4')
                c1[i-1]++;
            break;
        }
        p=i+1;
        c1[i]=s[i]-'0';
    }
    if(i<(p+N))
    {
        c1[i]=100;
        p=i+1;
        for(i=p;i<(p+N);i++)
            c1[i]=0;
    }
    int j1,j2,c2;
    for(j1=0,j2=i-1;j1<j2;j1++,j2--)
    {
        c2=c1[j1];
        c1[j1]=c1[j2];
        c1[j2]=c2;
    }
    for(j1=0;j1<i;j1++)
    {
        if(c1[j1]>=10&&c1[j1]!=100)
        {
            if(j1==(i-1))
                i++;
            if(c1[j1+1]==100)
            {
                c1[j1+2]=c1[j1+2]+c1[j1]/10;
                c1[j1]=c1[j1]%10;
                j1++;
            }
            else
            {
                c1[j1+1]=c1[j1+1]+c1[j1]/10;
                c1[j1]=c1[j1]%10;
            }
        }
    }
    for(j1=0,j2=i-1;j1<j2;j1++,j2--)
    {
        c2=c1[j1];
        c1[j1]=c1[j2];
        c1[j2]=c2;
    }
    for(j1=0;j1<i;j1++)
    {
        if(c1[j1]==0&&c1[j1+1]!=100);
        else
        {
            for(;j1<i;j1++)
            {
                if(c1[j1]==100)
                    printf(".");
                else
                    printf("%d",c1[j1]);
            }
            break;
        }
    }
}