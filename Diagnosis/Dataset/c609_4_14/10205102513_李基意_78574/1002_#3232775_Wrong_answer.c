#include <stdio.h>

int main() {
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        int pre=n%2;
        n/=2;
        int sum=1,max=sum;
        while(n){
            int temp=n%2;
            n/=2;
            if(pre==temp) sum=1;
            else sum++;
            if(sum>max) max=sum;
            pre=temp;
        }
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;

}
