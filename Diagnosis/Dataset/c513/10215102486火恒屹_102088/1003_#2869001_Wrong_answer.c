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
        int count1[10000]={0};
        for(int j=0;j<n;j++)
            {
                for(int k=0;k<64;k++)
                {
                    if(num[j]&1)
                        count1[j]++;
                    num[j]>>=1;
                }
            }
        int tmpt=0;
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(count1[j]<count1[k])
                {   tmpt=count1[k];
                    count1[k]=count1[j];
                    count1[j]=tmpt;
                    tmpt=num[k];
                    num[k]=num[j];
                    num[j]=tmpt;
                }
                else if((count1[j]==count1[k])&&(num[j]>num[k]))
                {
                    tmpt=num[k];
                    num[k]=num[j];
                    num[j]=tmpt;
                }
            }
        }
        printf("case #%d:\n",i);
        for(int j=0;j<n-1;j++)
        {
            printf("%d ",num[j]);
        }
        printf("%d\n",num[n-1]);
    }
    return 0;
}
