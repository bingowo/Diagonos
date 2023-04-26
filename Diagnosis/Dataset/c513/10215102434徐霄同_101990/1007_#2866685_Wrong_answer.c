#include <stdio.h>

int main()
{
    int t,i,j,k,n,x,x0,a0,k0;
    int a[32];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        j=0;
        x=0;
        while(n>0){
            a[j]=n%2;
            n=n/2;
            j++;
        }
        a0=a[0];
        for(k=0;k<j;k++){
            x0=0;
            k0=k;
            do{
                x0++;
                k0++;
                if(a0==0)
                    a0=1;
                else
                    a0=0;
            }while(k0==j || a0!=a[k0]);
            if(x0>x)
                x=x0;
        }
        printf("case #%d:\n",i);
        printf("%d\n",x);
    }
    return 0;
}