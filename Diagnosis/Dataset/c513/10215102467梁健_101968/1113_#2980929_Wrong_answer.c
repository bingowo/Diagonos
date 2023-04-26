#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

double list[150];

int main()
{
    int k,n;scanf("%d %d",&k,&n);
    for(int i=1;i<=k-1;i++)list[i]=0.0;
    list[k]=1.0;
    for(int i=k+1;i<150;i++)list[i]=-1.0;
    n=n+k-2;
    double solve(double list[],int n)
    {
        if(list[n]==-1.0){
            list[n]=0.0;
            for(int i=1;i<=k;i++){
                list[n]+=solve(list,n-i);
            }
            return list[n];
        }
        else return list[n];
    }
    printf("%.0lf",solve(list,n));
    return 0;
}
