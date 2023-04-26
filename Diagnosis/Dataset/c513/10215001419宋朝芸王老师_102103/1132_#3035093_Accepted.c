#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 40

typedef struct{
    char v[N];
    int cnt;
}BIG;

BIG convert(BIG A, long long int a, int digit){
    A.cnt = 0;
    while(a > 0){
        char temp = a%digit + '0';
        if(isdigit(temp)) A.v[A.cnt++] = temp;
        else A.v[A.cnt++] = temp - 10 - '0' + 'A';
        a = a/digit;
    }
    return A;
}

BIG add(BIG A, BIG B, int digit){
    int i = A.cnt;
    long long int ans = 0;
    for(int j = 0; j < i; j++){
        if(isdigit(A.v[j])) ans += A.v[j] - '0';
        else ans += A.v[j] - 'A' + 10;
    }
    B = convert(B,ans,digit);
    return B;
}


int main(){

    int T,R;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        long long int a;
        int digit;
        scanf("%lld%d",&a,&digit);

        BIG A,B;
        A = convert(A,a,digit);
        B = add(A,B,digit);

        printf("case #%d:\n",R);
        for(int i = B.cnt-1; i >= 0; i--)
            printf("%c",B.v[i]);
        printf("\n");

    }

}
