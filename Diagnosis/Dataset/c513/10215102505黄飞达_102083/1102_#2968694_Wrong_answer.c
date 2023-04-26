#include<stdio.h>
#include<math.h>
#define ll long long

int main(){
    ll n;
    scanf("%lld", &n);
    ll begin=0;
    ll temp=(ll)floor(sqrt(n));
    if (temp%2==0) temp--;
    ll x0=temp/2, y0=x0+1;
    ll dis = n-temp*temp;
    if (dis<=temp) {x0-=dis;dis=0;}
    else {
        x0-=temp;dis-=temp;
        if (dis<=temp+1){y0-=dis;dis=0;}
        else {
            y0-=temp+1;dis-=temp+1;
            if (dis<=temp+1) {x0+=dis; dis=0;}
            else {
                x0+=temp+1; dis-=temp+1;
                y0+=dis; dis=0;
            }
        }
    }
    printf("(%lld,%lld)\n", x0, y0);
    return 0;
}