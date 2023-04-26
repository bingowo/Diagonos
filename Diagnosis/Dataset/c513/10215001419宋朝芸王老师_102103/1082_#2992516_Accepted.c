#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 500

typedef struct{
    int f[1001];
}BIGF;


BIGF s2big(char *a, int len){
    int i = 0;
    while(a[i] != '.' && a[i] != '\0')
        i++; //position of the point
    BIGF r = {{0}};

    for(int j = 0; j < i; j++)
        r.f[M - i + j + 1] = a[j] - '0';
    for(int j = i + 1; j < len; j++)
        r.f[M + j - i] = a[j] - '0';

    return r;
}


BIGF add(BIGF a, BIGF b, int n){   //add + round
    BIGF r = {{0}};
    int t, i, carry = 0;

    for(i = 2*M; i > M + n; i--){
        t = a.f[i] + b.f[i] + carry;
        r.f[i] = t % 10;
        carry = t / 10;
    }
    if(r.f[i+1] >= 5) carry++;
    for(i = M + n; i >= 0; i--){
        t = a.f[i] + b.f[i] + carry;
        r.f[i] = t % 10;
        carry = t / 10;
    }

    return r;
}


int main()
{
    char A[2*M+1], B[2*M+1];
    int n;
    scanf("%s%s%d",A,B,&n);

    BIGF a,b,r;
    a = s2big(A,strlen(A)), b = s2big(B,strlen(B));
    r = add(a,b,n);

    int i = 0;
    while(r.f[i] == 0) i++;
    if(i > M) printf("0.");
    else{
       while(i < M+1)
            printf("%d",r.f[i++]);
       printf(".");
    }
    while(i <= M + n) printf("%d",r.f[i++]);

    return 0;
}
