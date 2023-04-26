#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bi[33];
int getBinary(int n)
{
    int i=0;
    while(n)
    {
        bi[i]=n%2;
        n/=2;
        i++;
    }
    return i;
}

int main()
{
    int T;
    scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int num=getBinary(n);
        int temp=1;
        int res=temp;
        for(int j=1;j<num;j++)
        {
            if(bi[j]!=bi[j-1])
                temp++;
            else
            {
                if(bi[j]==0)
                {
                    temp=0;
                    continue;
                }
                else
                    temp=1;
            }
            if(res<temp) res=temp;
        }
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}
