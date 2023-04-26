#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[101]={'\0'};
        scanf("%s",&s);
        char order[6]={'\0'};
        int kazu[6]={0};
        for(int j=0;j<strlen(s);j++)
        {
            if (s[j]!='!')
                order[j%4]=s[j];
            else
                kazu[j%4]++;
        }
        int flag[6]={0};
        for(int j=0;j<4;j++)
        {
            if(order[j]=='R')
                flag[0]=1;
            else if(order[j]=='B')
                flag[1]=1;
            else if(order[j]=='Y')
                flag[2]=1;
            else if(order[j]=='G')
                flag[3]=1;
        }
        int q;
        for(int j=0;j<4;j++)
        {
            if(flag[j]==0) q=j;
        }
        for(int j=0;j<4;j++)
        {
            if(order[j]==0)
            {
                if(q==0) order[j]='R';
                else if(q==1) order[j]='B';
                else if(q==2) order[j]='Y';
                else if(q==3) order[j]='G';
            }
        }
        int res[6]={0};
        for(int j=0;j<4;j++)
        {
            if(order[j]=='R')
                res[0]=kazu[j];
            else if(order[j]=='B')
                res[1]=kazu[j];
            else if(order[j]=='Y')
                res[2]=kazu[j];
            else if(order[j]=='G')
                res[3]=kazu[j];
        }
        for(int j=0;j<4;j++)
        {
            printf("%d ",res[j]);
        }
        printf("%c",10);
    }
    return 0;
}
