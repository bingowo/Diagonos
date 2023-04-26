#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    char mail[100000][10000]={'0'};
    int atto[10000]={0};
    for(int i=0;i<T;i++)
    {
        scanf("%s",&mail[i]);
        for(int j=0;j<strlen(mail[i]);j++)
        {
            if(mail[i][j]=='@')
                {atto[i]=j;
                break;}
        }
    }
    for(int i=0;i<T;i++)
    {
        int target=0;
        for(int j=0;j<T;j++)
        {
            if(atto[target]==0)
            {
                target++;
                continue;
            }
            if(target==j)
                continue;
            if(atto[j]==0)
                continue;
            int v=1;
            while((mail[target][atto[target]+v]==mail[j][atto[j]+v])&&(mail[target][atto[target]+v]!=0)&&(mail[j][atto[j]+v]!=0))
                v++;
            if(mail[target][atto[target]+v]>mail[j][atto[j]+v])
                target=j;
            else if(mail[target][atto[target]+v]==mail[j][atto[j]+v])
            {int cmp=strcmp(mail[target],mail[j]);
             if(cmp<0)
                target=j;}
        }
        printf("%s\n",mail[target]);
        atto[target]=0;
    }


    return 0;
}
