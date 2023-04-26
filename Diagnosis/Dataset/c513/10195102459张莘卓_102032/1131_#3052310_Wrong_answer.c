#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, flag = 1;
    scanf("%d %d",&A, &B);
    if(A < 0) A *= (flag = -1);
    int a = A/B, b = A%B;
    int num[100]={0}, cnt=0;
    while(b && b%3==0)  b /= 3;
    while(b) {
        num[cnt++] = b % 3;
        b /= 3;
    }
    int point = cnt, carry = 0;
    do {
        num[cnt++] = a % 3;
    }while(a /=3);
    for(int i=0; i<cnt; ++i) {
        num[i] += carry + 1;
        carry = num[i] / 3;
        num[i] = (num[i]%3 - 1) * flag; 
        if(num[i] < 0) num[i] = 2;
    }
    if(carry) num[cnt++] = flag==1? 1 : 2;
    for(int i=cnt-1; i>=point; --i) printf("%d",num[i]);
    if(point) {
        printf(".");
        for(int i=point-1; i>=0; --i) printf("%d",num[i]);
    }
    printf("\n");
    return 0;
}