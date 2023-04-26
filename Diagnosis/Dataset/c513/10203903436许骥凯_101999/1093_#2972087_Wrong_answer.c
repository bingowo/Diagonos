#include<stdio.h>
#include<string.h>

int find(const char *t, int lo, int hi){
    for (int i = lo; i <= hi; i++)
        if (t[i] == '9') return i;
    return -1;
}

int add1(char *t, int idx){
    int carry = 1;
    for (int i = idx; i >= 0; i--){
        int temp = carry + t[i] - '0';
        t[i] = temp % 10 + '0';
        carry = temp / 10;
        if (carry == 0) return i;
    }
    return -1;
}

int main(){
    char s[120] = {'0'}; scanf("%s", s+1);
    int len = strlen(s);
    int idx = find(s, 0, len - 1), flag;    
    if (idx == -1) flag = add1(s, len - 1);
    else flag = add1(s, idx);
    idx = find(s, 0, flag);
    while(idx != -1){
        flag = add1(s, idx);
        idx = find(s, 0, flag);
    }
    for (int i = flag + 1; i < len; i++)
        s[i] = '0';
    printf("%s\n", s + (s[0] == '0'? 1: 0));
    return 0;
}