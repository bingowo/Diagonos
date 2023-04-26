#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,w,x,y,z,cnt=0;
        scanf("%d",&n);
        for(w=n/4;w>=0;w--)
        {
            for(x=(n-4*w)/3;x>=0;x--)
            {
                for(y=(n-4*w-3*x)/2;y>=0;y--)
                {
                        if((4*w+3*x+2*y)<=n)
                            cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
