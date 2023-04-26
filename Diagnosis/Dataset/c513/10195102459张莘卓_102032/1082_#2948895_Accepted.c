#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int pi[501];
    int pf[501];
} BIG_DOU;

void getNumber(BIG_DOU *a) {
    char s[501];
    scanf("%s",s);
    char* point = strchr(s, '.');
    int len = (int)(point-s);
    if(point == NULL) len = strlen(s);
    for(int i=len-1; i>=0; --i)
        a->pi[len-1-i] = s[i] - '0';
    if(point){
        for(int i=len+1; s[i]; ++i)
            a->pf[i-len-1] = s[i] - '0';
    }
}
int max(int a, int b) {return a<b?b:a;}

int main()
{
    BIG_DOU A = {{0},{0}}, B = {{0},{0}}, C = {{0},{0}};
    getNumber(&A); getNumber(&B);
    int N;  scanf("%d",&N);
    int i, carry = 0;
    for(i=500; i>=0; --i) {
        C.pf[i] = (A.pf[i] + B.pf[i] + carry) % 10;
        carry = (A.pf[i] + B.pf[i] + carry) / 10;
    }
    for(i=0; i<501; ++i) {
        C.pi[i] = (A.pi[i] + B.pi[i] + carry) % 10;
        carry = (A.pi[i] + B.pi[i] + carry) / 10;
    }
    
    if(C.pf[N] > 4) {
        carry = 1;
        for(i=N-1; i>=0 && carry; --i){
            int t = C.pf[i] + carry;
            C.pf[i] = t % 10;
            carry = t / 10;
        }
        if(carry){
            for(i=0; i<501; ++i) {
                int t = C.pi[i] + carry;
                C.pi[i] = t % 10;
                carry = t / 10;
            }
        }
    }
    int start = 500;
    while(start>=0 && C.pi[start] == 0) --start;
    if(start < 0) printf("0");
    else for(i=start; i>=0; --i) printf("%d",C.pi[i]);
    printf(".");
    for(i=0; i<N; ++i) printf("%d",C.pf[i]);
    printf("\n");
    return 0;
}
