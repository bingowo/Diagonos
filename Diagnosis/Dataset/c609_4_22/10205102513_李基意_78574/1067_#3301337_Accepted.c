#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef long long ll;
ll feb[22];
ll febsum[22];
void getfeb() {
    feb[0] = feb[1] = 1;
    febsum[0] = 1, febsum[1] = 2;
    for (int i = 2; i < 22; i++)
    feb[i] = feb[i - 1] + feb[i - 2], febsum[i] = febsum[i - 1] + feb[i];
    return;
}
int main() {
    getfeb();
    int a,n,m,x,b;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    if (n <= 5) {
        if (x == 4)
            printf("%d",m);
        else
            printf("%d",((x + 1) / 2) * a);
    }
    else {
        b = (m - a * (2 + febsum[n - 6])) / febsum[n - 5];//m实际为n-1站发车的人数
        if (x < 4)
            printf("%d",((x + 1) / 2) * a);
            
        else if (x == 4)
            printf("%d",2 * a + b);
            
        else
            printf("%d",(2 + febsum[x - 5]) * a + febsum[x - 4] * b);
            
    }
    return 0;
}