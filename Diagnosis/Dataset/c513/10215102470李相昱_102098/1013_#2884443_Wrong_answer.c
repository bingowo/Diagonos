#include <stdio.h>
int gcd(int m,int n){
    if(!n)
        return m;
    else
        return gcd(n,m%n);
}
int main()
{
    char s[100];
    scanf("%s",s);
    int i = 0;
    int sign1 = 0;
    int ret1 = 0;
    while(s[i++]){
        if(s[i-1]!='.'){
            int m = ((s[i-1] -'0')==2?-1:(s[i-1]-'0'));
            ret1 = ret1 * 3 + m;
        }
        else{
            sign1 = 1;
            break;
        }
    }
    int r = 1;
    int num  = 0;
    int b = 0;
    while(s[i++]){
        int m = ((s[i-1] -'0')==2?-1:(s[i-1]-'0'));
        b = b*3+ m;
        r = r*3;
        num ++;
    }
    if(b<0){
        if(ret1){
            ret1 = ret1-1;
            b = r+b;
        }
    }
    int t = gcd(r,b);
    b = b/t;
    r = r/t;
    int sign2 =1;
    if (ret1 == 0){
        sign2 = 0;
    }
    if(sign2){
        printf("%d",ret1);
        if(sign1){
            printf(" ");
        }
    }
    if(sign1){
        printf("%d %d",b,r);
    }

    return 0 ;
}
