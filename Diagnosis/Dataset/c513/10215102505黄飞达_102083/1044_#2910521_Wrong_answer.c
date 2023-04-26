#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char s[100005];
    gets(s);
    int flag = 0;
    for (int i = 0; i < strlen(s); i++){
        if (i+1<strlen(s)){
            if (s[i+1] == 'x' && s[i]=='0'){
                if ((i+2<strlen(s) && s[i+2]>'f') || i+2>=strlen(s)) continue;
                else {
                    i+=2;
                    while(i<strlen(s)&&s[i]=='0')i++;
                }
                flag = 1;
                long long num = 0;
                for (i; i<strlen(s); i++){
                    if ('0'<=s[i] && s[i]<='9'){
                        num *= 16;
                        num += s[i] - '0';
                    }
                    else if ('a'<=s[i] && s[i]<='f'){
                        num *= 16;
                        num += s[i] - 'a' + 10;
                    }
                    else {
                        printf("%lld ", num);
                        break;
                    }
                }
                if (i >= strlen(s)-1) printf("%lld ", num);

            }
        }
    }
    if (flag == 0) printf("-1");
    printf("\n");
    return 0;
}