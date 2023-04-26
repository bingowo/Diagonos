#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(char s[])
{
    for(int i=0;i<strlen(s)-1;i++)
        if(s[i]==s[i+1]) return 1;
    return 0;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    char table[]="ABC";
    for(int i=0;i<T;i++)
    {
        char s[101]={0};
        scanf("%s",s);
        int len=strlen(s),max=0;
        for(int i=0;i<len+1;i++)//在每个位置插入字母
        {
            for(int j=0;j<3;j++)//循环每个字母
            {
                char sa[102]={0};
                for(int t=0;t<i;t++)
                    sa[t]=s[t];
                sa[i]=table[j];
                int t;
                for(t=i+1;t<len+1;t++)
                    sa[t]=s[t-1];
                //开始消除
                while(judge(sa))
                {
                    char sr[102]={0};
                    for(int l=0,r=1,in=0;sa[l];)
                    {
                         if(sa[l]==sa[r])
                         {
                             while(sa[r]&&sa[l]==sa[r])
                                 r++;
                             l=r,r+=1;
                          }
                          else
                              sr[in++]=sa[l],l++,r++;
                     }

                     if(sr[0])
                     {
                         strcpy(sa,sr);
                         if(max<len+1-strlen(sa)) max=len+1-strlen(sa);
                     }
                     else
                     {
                         max=len+1;
                         break;
                     }
                }
            }
        }
        printf("case #%d:\n%d\n",i,max);
    }
    return 0;
}