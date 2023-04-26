#include <stdio.h>

#define MAXN 21

int a[MAXN];
int aa[MAXN];
int f[MAXN];
int fa[MAXN];

int main() {
    f[0] = 0;
    a[0] = 0;
    int a1, n, am, fx;
    scanf("%d %d %d %d\n", &a1, &n, &am, &fx);
    f[1] = a1;
    f[2] = a1;
    fa[0] = 0;
    fa[1] = a1;
    fa[2] = a1;
    a[1] = a1;
    int x;
    a[2] = 1;
    aa[0] = 0;
    aa[1] = a1;
    aa[2] = 0;
    for (int i = 3; i < n; i++) {
        a[i] = a[i - 1] + a[i - 2];
        aa[i] = aa[i - 1] + aa[i - 2];
        //printf("%d %d\n", a[i], a[i-1]);
    }
    x=(am-a1-aa[n-1])/(a[n-1]-aa[n-1]);
    if(fx==1 || fx==2){
        printf("%d\n",a1);
        return 0;
    } else if(fx==3){
        printf("%d\n",2*a1);
        return 0;
    } else if(fx==4){
        printf("%d\n",2*a1+x);
        return 0;
    } else{
        printf("%d\n",a1-x+(a[fx]-aa[fx])*x+aa[fx]);
    }
//    for (int i = 3; i < n; i++) {
//        f[i] = f[i - 1] + a[i - 2];
//        fa[i] = fa[i - 1] + aa[i - 2];
//        //printf("%d %d\n", f[i], fa[i]);
//    }
//    x = (am - fa[n - 1]) / (f[n - 1] - fa[n - 1]);
//    for (int i = 3; i < n; i++)
//        f[i] = (f[i] - fa[i]) * x + fa[i];
//    printf("%d\n", f[fx]);
    return 0;
}