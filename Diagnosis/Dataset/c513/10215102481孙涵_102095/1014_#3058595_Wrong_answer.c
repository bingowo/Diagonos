#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    long long int c, d;
    c = a / b; //整数部分
    d = a % b; //分子
    int n = d;
    //分母是b;

    //开始转三进制
    int i = 0;
    int s1[100];//整数部分10->3
    for(i = 0; i < strlen(s1); i++){
        s1[i] = 0;
    }
    i = 0;
    do{
        s1[i] = c % 3;
        c = (c - s1[i]) / 3;
        i++;
    }while(c > 0);

    //按照正常顺序塞进总数数组
    int s[200];
    int j = 0,q;
    for(i = i-1;i>=0;i--,j++){
        s[j] =  s1[i];
    }
    q = j;
    //整数长度为j


    int s2[100];
    for (i = 0; i < strlen(s); i++){
        s2[i] = 0;
    }
    if(d != 0){//分数部分10->3
        int p = 0;
        do{
            s2[p] = d % 3;
            d = (d - s2[p]) / 3;
            p++;
            b = b / 3;
        }while(d > 0 || (b != 1));
        for(p = p - 1; p >= 0; p--,q++){
            s[q] = s2[p];
        }
    }


    //每一位加1;
    int l = 0;
    int t = q;
    for(q = q - 1; q >= 0; q--){
        if((s[q] + 1 + l) >= 3){
            s[q] = s[q] + 1 + l - 3;
            l = 1;
        }else{
            s[q] = s[q] + l + 1;
            l = 0;
        }
    }

    for(q = 0; q <= t; q++){
        if(s[q] - 1 == -1){
            s[q] = 2;
        }else{
            s[q] = s[q] - 1;
        }
    }

    for(q = q - 1; q >= j; q--){
        if(s[q] == 0){
            t = t - 1;
        }else{
            break;
        }
    }
    if(l == 1){
        printf("1");
    }
    for(int m = 0; m < t; m++){
        printf("%d",s[m]);
        if(n != 0){
            if(m == j - 1){
                printf(".");
            }
        }
    }
    return 0;
}
