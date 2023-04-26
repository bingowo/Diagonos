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
}

int main()
{
    int T;
    scanf("%d",&T);
    int n;
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        getBinary(n);
        int res=0;
        int temp=0;
        for(int j=0;j<33;j++)
        {
            if(bi[j]!=bi[j+1])
                temp++;
            else if(res<temp)
            {
                res=temp;
                temp=0;
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}
