#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isdigit(char c)
{
    return ('0'<=c&&c<='9');
}
int iscapital(char c)
{
    return('A'<=c&&c<='Z');
}
int islower(char c)
{
    return('a'<=c&&c<='z');
}
int main()
{
    int t,j;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        char s[100]={0};
        int a1[26]={0};//存大写字母
        int a2[26]={0};//存小写字母
        int a3[10]={0};//存数字
        int s1[100]={0};
        scanf("%s",s);
        int i=0,cnt=0,m=0;
        while(s[i])//进制
        {
            char c=s[i];
            if(islower(c))
            {
                if(!a1[c-'a'])
                {
                    a1[c-'a']=1;
                    cnt++; //几个字符
                }

            }
            else if(iscapital(c))
            {
                if(!a2[c-'A'])
                {
                    a2[c-'A']=1;
                    cnt++;
                }
            }
            else
            {
                if(!a3[c-'0'])
                {
                    a3[c-'0']=1;
                    cnt++;
                }
            }
            i++;
        }
        m=cnt==1?cnt+1:cnt;
        //求值
        long long  res=0;
        int p=0;
        for(i=0;i<strlen(s);i++)//
        {
            int tem,sign=0;
            if(i==0)
            {
                tem=1;
            }
            else
            {
                for(int k=0;k<i;k++)
                    {
                        if(s[i]==s[k])
                        {
                           tem=s1[k];
                           sign=1;
                            break;
                        }
                    }
                    if(!sign&&i==1)
                    {
                        tem=0;
                        p=2;
                    }
                    if(!sign&&i!=1)
                    {
                        tem=p++;
                    }
            }
            s1[i]=tem;
            res=(res+tem)*m;
        }
        res/=m;
        printf("case #%d:\n%lld\n",j,res);
    }
    return 0;
}
