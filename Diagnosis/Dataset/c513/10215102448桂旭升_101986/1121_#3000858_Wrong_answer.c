#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int fastPower(int base, int power) {
    int result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = result * base;
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base);
    }
    return result;
}
int cmp1(const void *a, const void *b){
    int pa = *(int*)a, pb = *(int*)b;
    return a<b ? -1:1;
}
int cmp2(const void *a, const void *b){
    int pa = *(int*)a, pb = *(int*)b;
    return a>b ? -1:1;
}
int main(){
	int i, j, d, flag, t, a[10], sub = 0;
    int *p = NULL, *temp = NULL;
    char c;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf("%d", &a[i]);
        sub += a[i];
    }
    int N = fastPower(2, t)-1;
    p = (int*)malloc(sizeof(int)*N);
    temp = p;
    qsort(a, t, sizeof(int), cmp2);
    *p++ = a[0];
    for(i = 1; i < t; i++){
        for(j = fastPower(2, i-1)-1; j < fastPower(2, i)-1; j++){
            *p++ = temp[j]+a[i];
            *p++ = temp[j]-a[i];
        }
    }
    p = temp;
    qsort(p, N, sizeof(int), cmp1);printf("%d\n", p[2]);
    while(*p <= 0)p++;
    for(i = 1; i <= sub; i++){
        if(i > *p)p++;
        if(i < *p)printf("0");
        if(i == *p){
            printf("1"); p++;
        }
    }
    system("pause");
	return 0;
}