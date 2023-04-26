#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show(int* a, int i, int end) {
    for(i=i-1; i>=0; --i){
        printf("%d",a[i]);
        if(i==end && i) printf(".");
    }
    printf("\n");
}

int main()
{
    int ternary[2000] = {0};
    int A, B;
    scanf("%d %d",&A, &B);
    if(A==0) {printf("0\n"); return 0;}
    
    int a = A/B, b = A%B, c = B;
    int i = 0;
    while(c != 1) {
        if(c == 3) {
            ternary[i++] = b;
            break;
        }
        c /= 3;
        ternary[i++] = b % c;
        b = (b - b%c) / 3;
    }
    int endint = i;
    do{
        ternary[i++] = a % 3;
        a /= 3;
    }while(a);
    
    int carry = 0;
    for(int k=0; k<i; ++k) {
        int sum = ternary[k] + carry + 1;
        ternary[k] = sum % 3;
        carry = sum / 3;
    }
    if(carry) ternary[i++] = carry + 1;
    
    for(int k=0; k<i; ++k) {
        ternary[k] ? --ternary[k] : (ternary[k] = 2);
    }
    int end = 0;
    while(ternary[end]==0 && end<endint)
        ++end;
    for(i=i-1; ternary[i]==0 && i>endint; --i);
    for(; i>=end; --i) {
        printf("%d",ternary[i]);
        if(i==endint && i!=end) printf(".");
    }
    printf("\n");
    return 0;
}
