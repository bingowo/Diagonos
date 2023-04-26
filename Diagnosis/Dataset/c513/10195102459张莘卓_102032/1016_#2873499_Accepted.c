#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, R, p=1;
    scanf("%d %d",&n, &R);
    R = -R;
    if(n < 0) {
        n = -n;
        p = 0;
    }
    int num[50] = {0};
    int i = 0;
    do{
        num[i++] = n % R;
        n /= R;
    }while(n);
    for(int k=0; k<i; ++k) {
        num[k+1] += num[k] / R;
        num[k] %= R;
        if(k % 2 == p && num[k]) {
            ++num[k+1];
            num[k] = R - num[k];
        }
    }
    while(num[i]) {
        num[i+1] += num[i] / R;
        num[i] %= R;
        if(i % 2 == p && num[i]) {
            ++num[i+1];
            num[i] = R - num[i];
        }
        ++i;
    }
    for(i=i-1; i>=0; --i){
        if(num[i] < 10) printf("%d",num[i]);
        else printf("%c",'A'+num[i]-10);
    }
    printf("\n");
    return 0;
}
