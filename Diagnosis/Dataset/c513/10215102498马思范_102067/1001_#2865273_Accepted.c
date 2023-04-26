#include <stdio.h>
#include <stdlib.h>

int main()
{
        int a;
        scanf("%d",&a);
        long long int b;
        int c;
        int d[1000];
        for(int i=0;i<a;i++)
        {   int j=0;
            scanf("%lld%d",&b,&c);
            if(b<0)
            {
                    printf("-");
                    b=-b;
            }
            while(b!=0)
            {
                d[j]=b%c;
                b=b/c;
                j++;
            }
            for(int m=j-1;m>=0;m--)
            {
                if(d[m]>=10)
                {
                    printf("%c",d[m]+'A'-10);
                }
                else
                {
                    printf("%d",d[m]);
                }
            }
            printf("\n");
        }
        return 0;

}