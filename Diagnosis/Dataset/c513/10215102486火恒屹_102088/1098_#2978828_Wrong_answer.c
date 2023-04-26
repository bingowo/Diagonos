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
        int res[6]={0};
        for(int j=1;j<5;j++)
        {
            if(order[j]=='R')
                res[1]=kazu[j];
            else if(order[j]=='Y')
                res[2]=kazu[j];
            else if(order[j]=='B')
                res[3]=kazu[j];
            else if(order[j]=='G')
                res[4]=kazu[j];
        }
        for(int j=1;j<5;j++)
        {
            printf("%d ",res[j]);
        }
        printf("%c",10);
    }
    return 0;
}
