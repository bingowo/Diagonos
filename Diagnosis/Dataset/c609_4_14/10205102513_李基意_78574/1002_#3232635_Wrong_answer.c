#include <stdio.h>

int main() {
    int t,n,a[32];
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        int d=0;
        while(n){
            a[d++]=n%2;
            n/=2;
        }
        int sum=1;
        for(int j=0;j<d-1;j++){
            if(a[j]==a[j+1]) break;
            else sum++;
            //printf("%d",a[j]);
        }

        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;

}
