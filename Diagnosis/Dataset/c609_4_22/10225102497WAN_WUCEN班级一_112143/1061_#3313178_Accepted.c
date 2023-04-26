#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

void MakePrimeTable(int n,int* PrimeTable);

int main()
{
    int n=0;
    long long int ans[N]={0};
    int Prime[200]={0};
    scanf("%d",&n);
    MakePrimeTable(n,Prime);
    ans[0]=1;
    for(int i=0;Prime[i]<=n&&Prime[i];i++)
    {
        for(int j=Prime[i];j<=n;j++)
            ans[j]+=ans[j-Prime[i]];
    }
    printf("%lld",ans[n]);
    return 0;
}


void MakePrimeTable(int n,int* PrimeTable)
{
    int* Erase;
    Erase=(int*)malloc((n*2)*sizeof(int));
    memset(Erase,0,2*n*sizeof(int));
    for(int i=2,j=0;i<=n;i++)
    {
        int erase=0;
        *(PrimeTable+j++)=i;
        for(int j=1;erase<n;j++)
        {
            erase=j*i;
            erase--;
            *(Erase+erase)=1;
        }
        i--;
        while(*(Erase+i))
            i++;
    }
    free(Erase);
}
