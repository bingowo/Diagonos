#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int N,n=0;
        scanf("%d",&N);
        if(N<5)printf("0\n");
        else
        {
            for(int i=5;i<=N;i+=5)
            {
                int k=0;
                if(5<=i&&i<25)k=1;
                else if(i<=25&&i<125)k=2;
                else if(i<=125&&i<725)k=3;
                else k=4;
                n+=k;
            }
            printf("%d\n",n);
        }
    }
}