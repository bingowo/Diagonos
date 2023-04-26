#include <stdio.h>
int main()
{
    int k,n;double a[100] = {0,1};
    scanf("%d %d",&k,&n);
    int i,j;
    if(n==1||n==2) printf("%d",(int)a[n-1]);
    else{
        for(i = 2;i<n;i++)
        {
            if(i<=k)
            {
                for(j = 0;j<i;j++)
                    a[i] += a[j];
            }
            else a[i] = 2*a[i-1]-a[i-k-1];
        }
        printf("%.f",a[n-1]);
    }
    return 0;
}
