//1079
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int Gcd(int a, int b){ 
    if(b == 0) return a; //当c1, c2可能为0时
    if(a < b) return Gcd(b, a);
    if(a%b == 0) return b;
    else return Gcd(b, a%b);
}
int main(){
    char s[20];
    scanf("%s", s);
    int a = 0, b = 0, c = 0, temp = 0, flag = 1, deta;
    for(int i = 0; i < strlen(s); i ++){  //读出来a, b ,c
        if(s[i] == '-') flag = -1;
        else if(s[i] >= '0' && s[i] <= '9') temp = temp*10+s[i]-48;
        else if(s[i] == 'x'){
            temp = (temp == 0)? 1*flag: temp*flag;
            if(s[i+1] == '^'){
                a = temp;
                i += 2;
            }else b = temp;
            temp = 0;
            flag = 1; 
        }
    }
    c = temp*flag;
    deta = b*b-4*a*c;
    int ret = (int)sqrt(deta), a1, c1, a2, c2;
    if(deta < 0 || ret*ret != deta) printf("No Answer!\n");
    else{
        a1 = 2*a; c1 = (-1*b+ret)*-1;
        temp = Gcd(abs(a1), abs(c1));
        a1 /= temp; c1 /= temp;
        if(a1 < 0){
            a1 *= -1;
            c1 *= -1;
        }
        a2 = 2*a; c2 = (-1*b-ret)*-1;
        temp = Gcd(abs(a2), abs(c2));
        a2 /= temp; c2 /= temp;
        if(a2 < 0){
            a2 *= -1;
            c2 *= -1;
        }
        if(a1 <= a2) printf("%d %d %d %d\n", a1, c1, a2, c2);
        else printf("%d %d %d %d\n", a2, c2, a1, c1);
    }
    return 0;
}