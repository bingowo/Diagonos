#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);

    for(int i=0; i<T; i++)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        int d=-1;//
        int a=0;
        while(n!=0)
        //for(int j=0; j<32; j++)
        {

            if((n&1)!=d)//优先级
            {
                a++;
                if(ans<a) ans=a;
            }
            else
            {
                a=1;
            }

            d=n&1;

            n=n>>1;
        }

        printf("case #%d:\n",i);
        printf("%d\n",ans);

    }
    return 0;
}
