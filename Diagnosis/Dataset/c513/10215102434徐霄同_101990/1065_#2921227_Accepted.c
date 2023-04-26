#include <stdio.h>

int main()
{
    int a0[20],b0[20];
    int a,n,m,x,x0,i,sum;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    a0[0]=a;
    a0[1]=0;
    b0[0]=0;
    b0[1]=1;
    for(i=2;i<n-1;i++){
        a0[i]=a0[i-1]+a0[i-2];
        b0[i]=b0[i-1]+b0[i-2];
    }
    x0=(m-a-a0[n-2])/(b0[n-2]-1);
    sum=a+a0[x-1]+x0*(b0[x-1]-1);
    if(x==1)
        printf("%d\n",a);
    else
        printf("%d\n",sum);
    return 0;
}
