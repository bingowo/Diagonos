#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    long long int a[t],i,sum,x,k,n;
    for(i=0;i<t;i++) scanf("%lld",&a[i]);
    for(i=0;i<t;i++){
        x=a[i];
        sum=1;
        k=x%2;
        x=x/2;
        while(x){
            if(x%2!=k){
                sum++;
                k=x%2;
                x=x/2;}
            else {
                    x=x/2;
                    break;
            }
        }
        while(x){
            n=1;
            while(x){
                if(x%2!=k){
                    n++;
                    k=x%2;
                    x=x/2;}
                else {
                    x=x/2;
                    break;}
            }
            if (n>sum) sum=n; }
        a[i]=sum;
        if(x==0&&k==0)a[i]--;
    }
    for (i=0;i<t;i++){
        printf("case #%lld:\n%lld\n",i,a[i]);
    }
    return 0;
}
