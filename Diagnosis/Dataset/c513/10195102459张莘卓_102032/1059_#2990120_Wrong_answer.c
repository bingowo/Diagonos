#include <stdio.h>

void gcdPrint(const int* p1, const int* p2) {
    int a = *p1, b = *p2;
    while(b) {
        int t = b;   b = a % b;   a = t;
    }
    printf("%d/%d\n",*p1/a, *p2/a);
}

int main()
{
    int n, s, i, width[1001] = {0};
    scanf("%d %d",&n, &s);
    for(i=0; i<n; ++i) {
        int height;
        scanf("%d",&height);
        ++width[height];
    }
    for(; i<1000 && width[i] < s; ++i) {
        s -= width[i];
        width[i+1] += width[i];
    }
    if(i == 1000) {
        printf("%d",1000+s/n);
        if(s %= n) {
            printf("+");
            gcdPrint(&s, &n);
        }else printf("\n");
    }else if(s == width[i]) printf("%d\n",i+1);
    else {
        if(i) printf("%d+",i);
        gcdPrint(&s, &width[i]);
    }
    return 0;
}
