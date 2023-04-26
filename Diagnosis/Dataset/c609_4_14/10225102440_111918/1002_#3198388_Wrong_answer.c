#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    long long int a[t],i,sum,x,k,n;
    for(i=0;i<t;i++) scanf("%d",&a[i]);
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
            else break;
        }
        while(x){
            n=1;
            while(x){
                if(x%2!=k){
                    n++;
                    k=x%2;
                    x=x/2;}
                else break;
            }
            if (n>sum) sum=n;
            x=x/2;}
        a[i]=sum;
    }
    for (i=0;i<t;i++){
        printf("case #%d:\n%d\n",i,a[i]);
    }
    return 0;
}