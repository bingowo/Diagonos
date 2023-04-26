#include <stdio.h>
#include <stdlib.h>

int reverseNumber(int n) {
    int ans = 0;
    while(n) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}

int isRound(int n) {
    int k = 0, i = -1, digit[10] = {0};
    while(n) {
        digit[++i] = n % 10;
        n /= 10;
    }
    while(k < i)
        if(digit[k++] != digit[i--]) return 0;
    return 1;
}

int getNUmber(int n, int* pcnt){
    (*pcnt)++;
    int m = reverseNumber(n);
    if(isRound(n + m))
        return m + n;
    else
        return getNUmber(m+n, pcnt);
}

int main()
{
    int n, cnt=0;
    scanf("%d",&n);
    int num = getNUmber(n, &cnt);
    printf("%d %d\n",cnt,num);
    return 0;
}