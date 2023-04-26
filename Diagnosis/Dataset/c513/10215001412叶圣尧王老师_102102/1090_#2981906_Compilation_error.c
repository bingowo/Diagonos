#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int N;scanf("%d",&N);
    while(N!=0)
    {
        long long sum=N;char a[10];
        for(i=1;i<N;i++)
        {
            sum=sum*N;
            if(sum>=1000000000)sum/=1000000000;
        }
        sprintf(a,"%d",sum);
        printf("%c\n",a[0]);
        scanf("%d",&N);
    }
}