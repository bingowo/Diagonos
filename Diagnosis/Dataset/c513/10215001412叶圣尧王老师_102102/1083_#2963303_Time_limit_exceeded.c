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
                int e,k=0;e=i;
                while(e/5)k++;
                n+=k;
            }
            printf("%d\n",n);
        }
    }
}