#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int result=0;
        int n;
        scanf("%d",&n);
        for(int j=1;j<=n;j++)
        {
            int temp=j;
            while(temp%5==0)
            {
                temp=temp/5;
                result++;
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",result);
    }
    return 0;
}