#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int a;
    scanf("%d",&a);
    for (int i=0;i<a;i++)
    {
        int n;
        scanf("%d",&n);
        int num[10000]={0};
        for(int j=0;j<n;j++)
            scanf("%d",&num[j]);
        char bin[10000][65]={'0'};
        for(int j=0;j<n;j++)
            itoa(num[j],bin[j],2);
        int count1[10000]={0};
        for(int j=0;j<n;j++)
            {
                for(int k=0;k<64;k++)
                {
                    if(bin[j][k]=='1')
                        count1[j]++;
                }
            }
        int tmpt=0;
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;j<n;j++)
            {
                if(count1[j]<count1[k])
                {
                    tmpt=count1[k];
                    count1[k]=count1[j];
                    count1[j]=tmpt;
                    tmpt=num[k];
                    num[k]=num[j];
                    num[j]=tmpt;
                }
                if((count1[j]=count1[k])&&(num[j]<num[k]))
                {
                    tmpt=count1[k];
                    count1[k]=count1[j];
                    count1[j]=tmpt;
                    tmpt=num[k];
                    num[k]=num[j];
                    num[j]=tmpt;
                }
            }
        }
        printf("case #%d:\n",i);
    }
    return 0;
}
