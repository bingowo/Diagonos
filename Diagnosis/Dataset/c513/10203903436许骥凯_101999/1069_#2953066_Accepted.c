#include<stdio.h>
#include<string.h>

int isT(char *s){
    int lo = 0, hi = strlen(s) - 1;
    while(lo <= hi)
        if (s[lo++] != s[hi--]) return 0;
    return 1;
}

void add(char *s){
    char temp[16] = {0}; int tlen = 14;
    int slen = strlen(s); int carry = 0;
    for (int i = slen - 1; i >= 0; i--){
        int t = (s[i] - '0') + (s[slen - i - 1] - '0') + carry;
        temp[tlen--] = t % 10 + '0';
        carry =  t / 10;
    }
    if (carry) temp[tlen--] = carry + '0';
    strcpy(s, temp + tlen + 1);
}

int pro(char *s, int times){
    if (isT(s)) return times;
    times++;
    add(s);
    pro(s, times);
}

int main(){
    char s[16]; scanf("%s", s);
    printf("%d %s\n", pro(s, 0), s);
    return 0;
}