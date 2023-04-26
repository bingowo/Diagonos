#include<stdio.h>
#include<string.h>
#define N 103

int duplicate(const char *s, int lo, int hi){
    for (int i = lo + 1; i <= hi; i++)
        if (s[i] == s[i-1]) return i;
    return -1;
}

int add1(char *s, int idx){
    int carry = 1;
    for (int i = idx; i >= 0; i--){
        int t = carry + s[i] - '0';
        s[i] = t % 10 + '0';
        carry = t / 10;
        if (carry == 0) return i;
    }
    return -1;

}


int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        printf("case #%d:\n", i);
        char s[N] = {'0'}; scanf("%s", s+1);
        int len = strlen(s), idx = duplicate(s, 0, len-1);
        int flag;
        if (idx == -1) flag = add1(s, len - 1);
        else flag = add1(s, idx);
        idx = duplicate(s, 0, flag);
        while(idx != -1){
            flag = add1(s, idx);
            idx = duplicate(s, 0, flag);
        }
        for (int j = flag+1; j < len; j+=2){
            s[j] = '0';
            if (j + 1 < len) s[j+1] = '1';  
        }
        printf("%s\n", s + (s[0] == '0'? 1: 0));
    }
    return 0;
}
