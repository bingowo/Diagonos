#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int e=0;e<T;e++)
    {
        int i,j,m,n;
        int num = 0;
        int s;
        scanf("%d",&s);
        for(i=0; i<= s/4;i++)
        for (j= 0; j<=s/3; j++)
        {
            if (4*i+3*j > s)
                break;
            for(m=0; m<=s/2;m++)
            {
                if (4*i+3*j+2*m > s)
                    break;
                for(n=0; n <= s; n++)
                {
                    if(4*i+3*j+2*m+n == s)
                    num++;
                }
            }

        }
        printf("%d\n",num);
    }
    return 0;
}
