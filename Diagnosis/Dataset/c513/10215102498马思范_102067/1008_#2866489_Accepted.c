#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d",&a);
    for(int j=0;j<a;j++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int num;
        num=x^y;
        int count=0;
        while(num!=0)
        {   if((num&1)!=0)
                count++;
            num=num>>1;
        }
        printf("%d",count);
        printf("\n");
    }
    return 0;
}