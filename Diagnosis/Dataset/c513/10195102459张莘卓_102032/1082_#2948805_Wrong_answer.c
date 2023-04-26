#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int pi[501];
    int pf[501];
} BIG_DOU;

int* getNumber(BIG_DOU *a) {
    char s[501];
    scanf("%s",s);
    char* point = strchr(s, '.');
    int len = (int)(point-s), *L = (int*)malloc(2*sizeof(int));
    if(point == NULL) len = strlen(s);
    L[0] = len; L[1] = 0;
    for(int i=len-1; i>=0; --i) a->pi[i] = s[i] - '0';
    if(point){
        for(int i=len+1; s[i]; ++i) a->pf[i-len-1] = s[i] - '0';
        L[1] = strlen(s) - len - 1;
    }
    if(point == s) L[0] = 1;
    else if(point && *(point+1)=='\0') L[1] = 1;
    return L;
}
int max(int a, int b) {return a<b?b:a;}

int main()
{
    BIG_DOU A = {{0},{0}}, B = {{0},{0}}, C = {{0},{0}};
    int *la = getNumber(&A), *lb = getNumber(&B);
    int N;  scanf("%d",&N);
    int lint = max(*la, *lb), ldou = max(la[1], lb[1]);
    free(la);  free(lb);
    int i, carry = 0;
    for(i=ldou-1; i>=0; --i) {
        C.pf[i] = (A.pf[i] + B.pf[i] + carry) % 10;
        carry = (A.pf[i] + B.pf[i] + carry) / 10;
    }
    for(i=0; i<lint; ++i) {
        C.pi[i] = (A.pi[i] + B.pi[i] + carry) % 10;
        carry = (A.pi[i] + B.pi[i] + carry) / 10;
    }
    if(carry) C.pi[lint++] = carry;
    
    if(C.pf[N] > 4) {
        carry = 1;
        for(i=N-1; i>=0 && carry; --i){
            int t = C.pf[i] + carry;
            C.pf[i] = t % 10;
            carry = t / 10;
        }
        if(carry){
            for(int i=0; i<lint; ++i) {
                int t = C.pi[i] + carry;
                C.pi[i] = t % 10;
                carry = t / 10;
            }
            if(carry) C.pi[lint++] = carry;
        }
    }
    while(lint && C.pi[lint-1] == 0) --lint;
    if(! lint) printf("0");
    else for(int i=lint-1; i>=0; --i) printf("%d",C.pi[i]);
    printf(".");
    for(int i=0; i<N; ++i) printf("%d",C.pf[i]);
    printf("\n");
    return 0;
}