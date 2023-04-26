#include<stdio.h>
#define MAXN 100
unsigned long long arr[MAXN];

void f(int k,int n)
{
    
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<100;i++)
    {
        int x=i-k;
        int y=0;
        while(x<i)
        {
            if(x<0)
            {
                x++;
            }
            else{
                y+=arr[x];
                x++;
            }
        }
        arr[i]=y;
    }
    
}

int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    f(n,k);
    printf("%llu\n",arr[n-1]);
    return 0;
}