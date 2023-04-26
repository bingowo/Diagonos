#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdio.h>
//long long labs(long long A){
//    if(A>=0) return A;
//    if(A<0) return -A;
//}

//long long GCD(long long A, long long B){
//    if(B==0) return A;
//    return GCD(B,A%B);
//}
int main(){
    int N,i;
    scanf("%d",&N);
    unsigned int p=0;
    long long A=0,B=0,C=1;
    char s[10][10000];
    for(i=0;i<N;i++) {
        scanf("%s", s[i]);
        for (p = 0; p < strlen(s[i]); p++) {
            if (s[i][p] == '.') break;
            else {
                A *= 3;
                if (s[i][p] == '0') A += 0;
                if (s[i][p] == '1') A += 1;
                if (s[i][p] == '-') A += -1;
            }
        }
        for(i=0;i<N;i++){
            printf("#case%d\n",i);
            printf("%lld\n",A);
        }
        
    }

//    p++;
//    for(;p<strlen(s);p++){
//        B*=3;
//        if (s[p] == '0') B += 0;
//        if (s[p] == '1') B += 1;
//        if (s[p] == '2') B += -1;
//        C*=3;
 //   }

//    long long t=GCD(labs(B),labs(C));
//    if (B==0) printf("%lld\n",A);
//    else
//    {   if (A!=0) printf("%lld ",A);
//        printf("%lld/%lld\n",B/t,C/t);
//    }

}