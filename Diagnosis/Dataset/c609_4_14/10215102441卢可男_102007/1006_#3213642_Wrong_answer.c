#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            if('a'<=c&&c<='z')
            {
                if(!a1[c-'a'])
                {
                    a1[c-'a']=1;
                    cnt++; //几个字符
                }

            }
            else if('A'<=c&&c<='Z')
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
        m=cnt;
        //求值，第一和第二位先算
        int res=0;
        res=(res+1)*m;
        s1[0]=1;
        res=(res+0)*m;
        s1[1]=0;
        int tem=0;
        for(i=2;i<strlen(s);i++)//
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
            s1[i]=tem;
            res=(res+tem)*m;
        }
        res/=m;
        printf("case #%d:\n%d\n",j,res);
    }
    return 0;
}
