#include<stdio.h>
#include<string.h>
int main(){
    int n;
    while(scanf("%d",&n)){
        if(n==-1)break;
        int a[20];
        a[0]=0;
        a[1]=2;
        a[2]=4;
        a[3]=7;
        a[4]=12;
        if(n<=4){printf("%d\n",a[n]);continue;}
        else{
            int k=5;
            while(k<=n){
                a[k]=2*a[k-1]-a[k-2]+a[k-3];
                k++;
            }
        }
        printf("%d\n",a[n]);

    }
    return 0;
}