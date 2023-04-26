#include <stdio.h>
#include <string.h>

int main()
{
    char s[30];
    scanf("%s", s);
    long long z = 0;
    int i = 0;
    while (i < strlen(s) && s[i] != '.'){
        if (s[i] != '2'){
            z = z * 3 + s[i] - '0';
        }
        else{
            z = z * 3 - 1;
        }
        i ++;
    }  //读取整数部分
    long long a = 0, b = 1;  //a存储分子数据，b存储分母数据
    if (i == strlen(s)){
        printf("%lld", z);
    }
    else{
        i ++;
        while (i < strlen(s)){
            b *= 3;
            if (s[i] != '2'){
                a = a * 3 + s[i] - '0';
            }
            else{
                a = a * 3 - 1;
            }
            i ++;
        }
        if (z == 0){
            printf("%lld %lld", a, b);
        }
        else{
            long long A, B, C = b;
            if (z > 0){
                if (a > 0) {A = z; B = a;}
                else {A = z - 1; B = a + b;}
            }
            else{
                if (a > 0) {A = z + 1; B = b - a;}
                else {A = z; B = -a;}
            }
            printf("%lld %lld %lld", A, B, C);
        }
    }
    return 0;
}
