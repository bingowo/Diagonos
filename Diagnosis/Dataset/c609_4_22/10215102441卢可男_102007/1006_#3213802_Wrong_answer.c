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
                    m=c-'0'<m?m:c-'0';
                    cnt++;
                }
            }
            i++;
        }
        m=cnt<m+1?m+1:cnt;
        //求值，第一和第二位先算
        long long  res=0;
        if(iscapital(s[0])||islower(s[0]))
        {
            s1[0]=1;
        }
        else
        {
            s1[0]=s[0]-'0';

        }
        res=(res+s1[0])*m;
        if(iscapital(s[0])||islower(s[0]))
        {
            s1[1]=0;
        }
        else
        {
            s1[1]=s[1]-'0';

        }
        res=(res+s1[1])*m;
        int tem=0;
        for(i=2;i<strlen(s);i++)//
        {
           if(iscapital(s[0])||islower(s[0]))
           {
                tem=i;
                int k;
                for(k=0;k<i;k++)
                {
                    if(s[i]==s[k])
                    {
                       tem=s1[k];
                        break;
                    }
                }
           }
           else
           {
                tem=s[i]-'0';
           }

            s1[i]=tem;
            res=(res+tem)*m;
        }
        res/=m;
        printf("case #%d:\n%lld\n",j,res);
    }
    return 0;
}
