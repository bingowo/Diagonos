#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[121];
        scanf("%[^\n]",s);
        int x=0,y=0;//0、1的位数
        for(int j=0;j<sizeof(s)/sizeof(s[0]);j++)
        {
            int a=(int)s[j];
            int d=1;
            for(int k=0;k<8;k++)
            {
                if(a&d) y++;
                else x++;
                d=d<<1;
            }
        }
        int z=x+y;//分母
        int max;//最大公约数
        for(int j=y;j>0;j--)
        {
            if(z%j==0 && y%j==0)
            {
                max=j;
                break;
            }
        }
        printf("%d/%d\n",y/max,z/max);
    }
    return 0;
}