#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
int main(){
    long long int x,y;
    long long int distance;
    int k;
    scanf("%lld %lld",&x,&y);
    distance=fabs(x)+fabs(y);
    if(distance%2==0){
        printf("-1");
    }else if(x==0&&y==0){
        printf("-1");
    }
    else{
        k=1;
        long long int min=1,max=2;
        int res=0;
        for(int i=0;i<42;i++){
            if((min<distance)+1&&(distance+1)<=max){
                res=1;
                break;
            }else{
                k++;
                min*=2;
                max*=2;
            }
        }
        if(res==0) printf("-1");
        else printf("%d",k);
    }
}