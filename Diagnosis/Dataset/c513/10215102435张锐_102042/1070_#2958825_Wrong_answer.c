#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        int sum=(int)pow(2,n);
        for(int i=(int)pow(2,n+1)-1;i>=0;i--)
        {
            int temp=i;
            while(temp)
            {
                if(temp%2==1)
                {
                    if((temp>>1)%2==0)
                    {
                        if((temp>>2)%2==0) {sum--;break;}
                    }
                }
                temp=temp/2;
            }
        }
        printf("%d\n",sum);
        scanf("%d",&n);
    }
    return 0;
}