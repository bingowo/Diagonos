#include<stdio.h>
#include<math.h>
#define ll long long

int main(){
    ll n;
    scanf("%lld", &n);
    if (n==0) {printf("(0,0)\n"); return 0;}
    ll begin=0;
    ll temp=(ll)sqrt(n)-1;
    if (temp*temp+2*temp+1<=n) temp++;
    if (temp%2==0) temp--;
    ll x0=temp/2, y0=x0+1;
    ll dis = n-temp*temp;
    if (dis<=temp) {x0-=dis;}
    else {
        x0-=temp;dis-=temp;
        if (dis<=temp+1){y0-=dis;}
        else {
            y0-=temp+1;dis-=temp+1;
            if (dis<=temp+1) {x0+=dis;}
            else {
                x0+=temp+1; dis-=temp+1;
                y0+=dis;
            }
        }
    }
    printf("(%lld,%lld)\n", x0, y0);
    return 0;
}