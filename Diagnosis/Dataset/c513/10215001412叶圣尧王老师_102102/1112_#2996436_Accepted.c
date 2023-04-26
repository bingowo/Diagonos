#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n,w,x,y,z,num=0;
        scanf("%d",&n);
        for(w=0;w*4<=n;w++)
        {
            for(x=0;w*4+x*3<=n;x++)
            {
                for(y=0;w*4+x*3+y*2<=n;y++)
                {
                    num++;
                }
            }
        }
        printf("%d\n",num);
    }
}
