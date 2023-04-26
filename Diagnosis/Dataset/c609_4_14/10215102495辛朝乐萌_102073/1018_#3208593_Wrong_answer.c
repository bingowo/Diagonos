#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int ff(int n)
{
    if (n>=0) return n;
    else return -n;
}

int main()
{
    int t;
    scanf("%d",&t);
    int a[t];
    int max=9999,mmm=9999;
    int ju;
    for(int i=0;i<t;i++){
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < t-1; ++i) {
        for (int j = i; j < t; ++j) {
            ju= ff(a[i]-a[j]);
            max=max<ju?max:ju;
        }
        mmm=mmm<max?mmm:max;
    }
    printf("%d",mmm);

    return 0;
}
