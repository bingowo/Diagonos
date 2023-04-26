#include <stdio.h>
#include <string.h>

long long longabs(long long A){
    if(A>=0) return A;
    if(A<0) return -A;
}

long long GCD(long long A, long long B){
    if(B==0) return A;
    return GCD(B,A%B);
}

int main() {

    unsigned int p = 0;
    long long A = 0, B = 0, C = 1;
    char s[10000];

    scanf("%s", s);
    A = 0;
    for (p = 0; p < strlen(s); p++) {
        if (s[p] == '.') break;
        else {
            A *= 3;
            if (s[p] == '0') A += 0;
            if (s[p] == '1') A += 1;
            if (s[p] == '2') A -= 1;
        }
    }
    p++;
    for(;p<strlen(s);p++){
        B*=3;
        if (s[p] == '0') B += 0;
        if (s[p] == '1') B += 1;
        if (s[p] == '2') B += -1;
        C*=3;
    }
    long long t=GCD(longabs(B),longabs(C));

    if(B<0 && A>0){
        B=B+C;
        A--;
    }
    if(B>0 && A<0){
        A++;
        B=C-B;
    }//小数部分，正负依赖于正数部分
    if (B==0) printf("%lld\n",A);
    else
    {   if (A!=0) printf("%lld ",A);
        printf("%lld %lld\n",B/t,C/t);
    }
    return 0;
}
//GCD函数要记下来