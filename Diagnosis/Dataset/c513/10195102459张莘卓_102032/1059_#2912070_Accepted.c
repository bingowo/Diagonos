#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fractionpr(int a, int b) {
    int n = a, m = b;
    while(m) {
        int t = n % m;
        n = m;
        m = t;
    }
    printf("%d/%d",a/n,b/n);
}

int main()
{
    int n, s, a[1000];
    scanf("%d %d",&n, &s);
    int k=0, min=1001;
    for(int i=0; i<n; ++i) {
        scanf("%d",&a[i]);
        if(a[i] < min) {
            min = a[i];
            k = i;
        }
    }
    int h = min, width = 1;
    while(s) {
        int i = k, j = k;
        while(i>0 && a[i-1]<h+1) --i;
        while(j+1<n && a[j+1]<h+1) ++j;
        width = j - i + 1;
        if(width <= s){
            s -= width;
            ++h;
        }else break;
    }
    if(s == 0) printf("%d",h);
    else {
        if(h) printf("%d+",h);
        fractionpr(s, width);
    }
    printf("\n");
    return 0;
}