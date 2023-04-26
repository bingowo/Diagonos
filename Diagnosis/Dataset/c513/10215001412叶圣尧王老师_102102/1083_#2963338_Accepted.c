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
                if(i%625==0)k=4;
                else if(i%125==0)k=3;
                else if(i%25==0)k=2;
                else k=1;
                n+=k;
            }
            printf("%d\n",n);
        }
    }
}