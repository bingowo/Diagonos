
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int T,col[20],cnt[20];
char s[10005];

int main()
{
    scanf("%d",&T);
    for(int c=0;c<T;c++)
    {
        scanf("%s",s);
        cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
        col[0]=col[1]=col[2]=col[3]=-1;
        for(int i=0;s[i];i++)
        {
            if(s[i]!='!')
            {
                if(s[i]=='R')
                    col[i%4]=0;
                else if(s[i]=='B')
                    col[i%4]=1;
                else if(s[i]=='Y')
                    col[i%4]=2;
                else
                    col[i%4]=3;
            }
        }
        for(int i=0;i<4;i++)
        {
            if(col[i]==-1)
            {
                col[i]=6;
                for(int j=0;j<4;j++)
                    if(i!=j)
                        col[i]-=col[j];
            }
        }
        for(int i=0;s[i];i++)
        {
            if(s[i]=='!')
                cnt[col[i%4]]++;
        }
        printf("case #%d:\n",c);
        for(int i=0;i<4;i++)
            printf("%d ",cnt[i]);
        puts("");
    }
    return 0;
}