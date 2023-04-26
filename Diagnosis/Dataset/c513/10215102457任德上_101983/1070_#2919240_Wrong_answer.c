#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)){
        int sum,end,m;
        if(n==-1)break;
        if(n==1||n==2)sum=0;
        else if(n==3)sum=1;
        else{
            m=n-3;
            sum=n-2;
            while(m-->0)sum*=2;
        }
        end=(int)pow(2,n)-sum;
        printf("%d\n",end);
    }
    return 0;
}