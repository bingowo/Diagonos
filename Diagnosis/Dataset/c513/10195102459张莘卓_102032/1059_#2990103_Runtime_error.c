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
    for(i=0; width[i]==0; ++i);
    for(; width[i] < s; ++i) {
        s -= width[i];
        width[i+1] += width[i];
    }
    if(s == width[i]) printf("%d\n",i+1);
    else {
        if(i) printf("%d+",i);
        gcdPrint(&s, &width[i]);
    }
    return 0;
}
