#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mod 1000000007

long long quickMult(long long a, int b) {
    long long ans = 1, mult = a;
    while(b > 0) {
        if(b % 2) ans = ans * mult % mod;
        mult = mult * mult % mod;
        b /= 2;
    }
    return ans;
}

int main()
{
    char word[1001];
    scanf("%s",word);
    if(strlen(word) == 1) {
        printf("1\n");
        return 0;
    }
    int c2 = 0, c3 = 0;
    for(int i=0; word[i]; ++i) {
        if(i == 0) {
            if(word[1] != word[0]) ++c2;
        }else if(i == strlen(word)-1) {
            if(word[i] != word[i-1]) ++c2;
        }else {
            if(word[i]!=word[i-1] && word[i]!=word[i+1] && word[i-1]!=word[i+1]) ++c3;
            else if(word[i-1]!=word[i] || word[i+1]!=word[i]) ++c2;
        }
    }
    long long n1 = quickMult(2, c2);
    long long n2 = quickMult(3, c3);
    printf("%d\n",(int)(n1*n2%mod));
    return 0;
}
