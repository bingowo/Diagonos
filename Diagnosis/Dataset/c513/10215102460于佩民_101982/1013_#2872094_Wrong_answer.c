#include <stdio.h>
#include <string.h>

int main(){
    char s[40];
    scanf("%s",s);
    unsigned int p=0;
    long long ansA=0;
    long long ansB=0, ansC=1;
    for (;p<strlen(s);p++) {
    if (s[p]=='.') break;
    ansA = ansA *3;
    if (s[p]=='1') ansA += 1;
    if (s[p]=='2') ansA -= 1;
    }
    p++;
    for (;p<strlen(s);p++) {
    ansB =ansB * 3;
    if (s[p]=='2') ansB -= 1;
    if (s[p]=='1') ansB += 1;
    ansC = ansC * 3;
}
    if(ansB>0&&ansC<0){
        ansB=-ansB;
        ansC=-ansC;
    }
    if(ansA==0) printf("%d %d",ansB,ansC);
    if(ansA!=0){
        if(ansB==0) printf("%d",ansA);
        if(ansB!=0) printf("%d %d",ansB,ansC);
    }
    return 0;
}