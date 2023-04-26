#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void myAdd(char res[], int num){
    int len = strlen(res);
    memmove(res + 1, res, len+1);
    res[0] = num + '0';
    //puts(res);
    return;
}

void myDivide(char res[], char temp[]){
    int len = strlen(res);
    int t, r = res[0]-'0', q = 0, index = 0;
    for (int i = 0; i < len || r != 0; i++){
        if (i >= len-1){
            t = r * 10;
        }
        else{
            t = r * 10 + res[i+1] - '0';
        }
        q = t / 8;
        r = t % 8;
        temp[index++] = q + '0';
    }
    //puts(res);
    return;
}

int main(){
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++){
        char s[100], res[200] = {0}, temp[200] = {0};
        scanf("%s", &s);
        memmove(s, s+2, strlen(s)-1);
        int slen = strlen(s);
        for (int i = slen-1; i >= 0; i--){
            myAdd(res, s[i]-'0');
            myDivide(res, temp);
            int tlen = strlen(temp);
            memmove(res, temp, tlen+1);
        }
        printf("case #%d:\n", i);
        printf("0.%s\n", res);
    }
    return 0;
}