#include<stdio.h>
#include<math.h>
int main(){
    int t;
    scanf("%d",&t);
    int cas=0;
    while(t--){
        long long int n;
        scanf("%lld",&n);
        int cnt=0;
        for(int b=2;;b++){
            if(pow(n,1.0/b)<2)break;
            int a=(int)(pow(n,1.0/b)+0.5);
            if(fabs(pow(n,1.0/b)-a)<0.000001){
                if(cnt==0){
                    printf("%lld=%d^%d",n,a,b);
                }
                else printf("=%d^%d",a,b);
                cnt++;
            }
        }
        if(cnt==0)printf("%lld is powerless.",n);
        putchar('\n');
    }
}