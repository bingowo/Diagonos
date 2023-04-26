#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int GCD(int m,int n)
{
    int temp;
    if(m < n) temp = m, m = n, n = temp;     //m中放较大数
    if(m%n == 0) return n;
    temp = n, n = m%n, m = temp;
    return(GCD(m,n));
}


int main(){
    char input[32];
    int flag = 0;
    scanf("%s",input);
    //int len = strlen(input);    //共有len个字符

    int a = 0, b = 0, c = 0;  //分别表示整数部分，带分数的分子、分母
    char *p = input;

    while(*p != '.' && *p){
        switch(*p){
            case '2': a = a*3 - 1;  break;
            case '1': a = a*3 + 1;  break;
            case '0': a = a*3;      break;
        }
        p++;
    }

    if(*p == '.') {
        p++;
        flag = 1;
    }

    while(*p != '.' && *p && flag ==1){
        c++;
        switch(*p){
            case '2': b = b*3 - 1; break;
            case '1': b = b*3 + 1; break;
            case '0': b = b*3; break;
        }
        p++;
    }

    if(flag == 1){
        c = pow(3,c);
        int gcd = GCD(abs(b),c);
        b /= gcd;
        c /= gcd;
    }

    if(a > 0 && b < 0){
        a--;
        b = c - abs(b);
    }
    if(a < 0 && b < 0){
        b = -b;
    }
    if(a < 0 && b > 0){
        a++;
        b = c - abs(b);
    }

    if(a != 0 && b != 0) {printf("%d %d %d",a,b,c); return 0;}
    if(a == 0 && b != 0) {printf("%d %d",b,c); return 0;}
    if(b == 0) {printf("%d",a); return 0;}

    return 0;
}
