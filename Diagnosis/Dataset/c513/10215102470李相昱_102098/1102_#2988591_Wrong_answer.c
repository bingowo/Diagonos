#include <stdio.h>
#include <math.h>
int main() {
    long long x,y;
    long long int n;
    scanf("%lld",&n);
    int a= (int)sqrt((double)n);
    long long int a2=a*a;
    if(a2==n){
        if(a%2){
            x=(a-1)/2;
            y=x+1;
        }else{
            x=-a/2;
            y=x;
        }
    }else{
        int b = a+1;
        int end;
        int a3= n-a2;
        if(a%2){
            x=(a-1)/2;
            y=x+1;
            end =-b/2;
            if(a3>=x-end){
                y=y-(a3-(x-end));
                x=end;
            }else{
                x=x-a3;
            }
        }else{
            x=-a/2;
            y=x;
            end =(b-1)/2;
            if(a3>=end-x){
                y=y+a3-(end-x);
                x=end;
            }else{
                x=x+a3;
            }
        }
    }
    printf("(%d,%d)",x,y);

    return 0;
}
