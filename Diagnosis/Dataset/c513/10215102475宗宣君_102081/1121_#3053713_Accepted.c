#include <stdio.h>
int ispossible(int*w,int n,int flag)
{
    int a[3] = {-1,0,1},i;
    if(flag==0) return 1;
    if(n==0) return 0;
    else{
        for(i = 0;i<3;i++)
            {
                int m = ispossible(w,n-1,flag+a[i]*w[n-1]);
                if(m==1) return 1;
            }
    }
}
int main()
{
    int n,sum = 0;
    scanf("%d",&n);
    int w[10],i;
    for(i = 0;i<n;i++)
    {
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    for(i = 1;i<=sum;i++)
    {
        printf("%d",ispossible(w,n,i));
    }
    return 0;

}
