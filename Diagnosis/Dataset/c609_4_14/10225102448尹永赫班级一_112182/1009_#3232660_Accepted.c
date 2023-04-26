#include <stdio.h>
#include <string.h>

int gcd(int m, int n){
    for (int i = m; i >= 1; i--)
        if (m % i == 0 && n % i == 0)
            return i;
}

int getOne(char c){
    int cnt = 0;
    if(c<0){
        cnt++;
        c ^= 128;
    }
    while(c){
        if(c%2) cnt++;
        c /= 2;
    }
    return cnt;
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        char str[125] = {'\0'};
        char ch;
        int index = 0;
        while((ch = getchar()) != '\n')
            str[index++] = ch;
        int length = strlen(str);
        int oneDigits = 0;
        for(int j = 0; j < length; j++)
            oneDigits += getOne(str[j]);
        int totalDigits = length*8;
        int g = gcd(oneDigits, totalDigits);
        oneDigits /= g;
        totalDigits /= g;
        printf("%d/%d\n", oneDigits, totalDigits);
    }
    return 0;
}