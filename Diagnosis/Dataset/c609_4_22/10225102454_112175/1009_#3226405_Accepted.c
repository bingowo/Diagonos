#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
int min(int a, int b){ return a > b ? b: a; }
int max(int a, int b){ return a < b ? b: a; }


// int main(void)
// { 
   

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

int GCD(int m,int n){
    return n ? GCD(n, m % n) : m;
}


int main(){
    int n;
    int a,b;
    unsigned int t;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        b=0;
        char s[1000];
        fgets(s,1000,stdin);
        int a = strlen(s) - 1;
        for(int x=0;x < a;x++){
            t=(unsigned char)s[x];
            while(t){
                b=b+(t&1);
                t=t>>1;
            }
            }
        a *= 8;
        int gcd = GCD(a, b);
        printf("%d/%d\n",b/gcd,a/gcd);
    }
return 0;
}