#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

long long list[120];

int main()
{
    int k,n;scanf("%d %d",&k,&n);
    for(int i=1;i<=k-1;i++)list[i]=0;
    list[k]=1;
    for(int i=k+1;i<120;i++)list[i]=-1;
    n=n+k-2;
    long long solve(long long list[],int n)
    {
        if(list[n]==-1){
            list[n]=0;
            for(int i=0;i<k;i++){
                list[n]+=solve(list,n-i);
            }
            return list[n];
        }
        else return list[n];
    }
    printf("%lld",solve(list,n));
    return 0;
}
