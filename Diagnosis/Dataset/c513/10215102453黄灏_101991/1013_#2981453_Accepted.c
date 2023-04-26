#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long int GCD(long long int a,long long int b){//最大公约数
    long long int max=b;
    long long int min=a;
    while (max%min){
        long long int temp=max%min;
        max =min;
        min = temp;
    }
    return min;
}

int main() {
    unsigned int p=0;
    long long ansA=0; //转换得到的整数
    long long ansB=0,ansC=1;//转换得到的分子，分母；
    char s[31];
    scanf("%s",s);
    for(;p<strlen(s);p++){//整数部分
        if(s[p]=='.') break;
        ansA =ansA*3;
        if(s[p]=='1') ansA +=1;
        if(s[p]=='2') ansA -=1;
    }
    p++;
    for(;p< strlen(s);p++){//小数部分
        ansB = ansB*3;//分子
        if(s[p]=='2') ansB-=1;
        if(s[p]=='1') ansB+=1;
        ansC = ansC*3;//分母；
    }
    if(ansA!=0 && ansB<0){
        ansA--;
        ansB = ansC+ansB;
    }
    else if(ansA<0 && ansB>0){
        ansA++;
        ansB = ansC-ansB;
        if(ansA==0){
            ansB=-ansB;
        }
    }
    if(ansB==0) printf("%lld\n",ansA);
    else{
        long long int t=GCD(abs(ansB), abs(ansC));
        if(ansA!=0) printf("%lld ",ansA);
        printf("%lld %lld\n",ansB/t,ansC/t);
    }

    return 0;
}
