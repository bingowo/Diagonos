#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n); getchar();
    for (int i = 0; i != n; i++){
        char s[101] = {0}; int len = 0, flen = 1;
        char c; c = getchar();
        while(c != '\n'){
            char temp;
            temp = getchar();
            if (temp == c || temp == '\n'){
                if (len != 0 && s[len-1] == temp) s[--len] = 0;      
            } 
            else{
                if (len == 0) s[len++] = c;
                s[len++] = temp;
            }
            c = temp;
            flen++;
        }

        int left = 0, right = 0, slen = 0, tlen = 0;
        for (int j = 0; j < len - 2; j++){
            if (s[j] == s[j + 2]){
                if (!left) left = j;
                right = j + 2;
            }
            else{
                tlen = right - left;
                if (tlen > slen) slen = tlen;
                left = 0; right = 0;
            }
        }
        tlen = right - left;
        if (tlen > slen) slen = tlen;

        printf("%d\n", flen - len + (len > 0? ++slen: slen));
    }
}