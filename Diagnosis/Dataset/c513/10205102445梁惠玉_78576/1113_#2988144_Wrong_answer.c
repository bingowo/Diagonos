#include<stdio.h>
unsigned long long f(int k,int n)
{
    unsigned long long arr[50];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<50;i++)
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
    return arr[n-1];
}

int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    printf("%llu\n",f(n,k));
    return 0;
}