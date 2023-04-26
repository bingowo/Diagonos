#include<stdio.h>
#include<string.h>
#include<math.h>
#define max(a, b) ((a) > (b)? (a): (b))
 
int isPrime(int n){
    if (n < 2) return 0;
    if (!(n % 2)) return 0;
    if (n == 2) return 1;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (!(n % i)) return 0;
    return 1;
}

void reverse(int *arr, int lo, int hi){
    while(lo <= hi){
        int temp = arr[lo];
        arr[lo++] = arr[hi];
        arr[hi--] = temp;
    }
}

#define MAXLEN 26

int main(){
    int T; scanf("%d", &T); getchar();
    int table[MAXLEN]; table[0] = 2;
    for (int i = 1, num = 3; i != MAXLEN; ){
        if (isPrime(num)) table[i++] = num;
        num += 2;
    }
    for (int i = 0; i != T; ++i){
        printf("case #%d:\n", i);
        int s[MAXLEN] = {0}, t[MAXLEN] = {0}, slen = 0, tlen = 0; char c;
        do{
            scanf("%d", &s[slen++]);
        }while((c = getchar()) != ' ');
        do{
            scanf("%d", &t[tlen++]);
        }while((c = getchar()) != '\n');
        reverse(s, 0, slen - 1);
        reverse(t, 0, tlen - 1);

        int carry = 0, j = 0;
        int len = max(slen, tlen), res[MAXLEN] = {0};
        for (; j != len; ++j){
            int temp = carry + s[j] + t[j];
            res[j] = temp % table[j];
            carry = temp / table[j];
        }
        while(carry){
            res[j] = carry % table[j];
            carry /= table[j];
            ++j; 
        }
        for (int k = j - 1; k >= 0; --k)
            printf("%d%c", res[k], k == 0? '\n': ',');
    }
    return 0;
}