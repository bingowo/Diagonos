#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[500];
    scanf("%s", s);
    char s1[3000] = "00010000000000",s2[10];
    int n;
    int len = strlen(s);
    n = len;
    for(int j = 9;j >= 0;j--){
        s1[4 + j] = (char)('0' + n % 2);
        n /= 2;
    }
    for(int i = 0;i < len/3;i++){
        n = (int)(s[3 * i] - '0') * 100 + (int)(s[3 * i + 1] - '0') * 10 + (int)(s[3 * i + 2] - '0');
        int len1 = strlen(s1);
        for(int j = 9;j >= 0;j--){
            s1[len1 + j] = (char)('0' + n % 2);
            n /= 2;
        }
    }
    if(len % 3 == 1){
        n = s[len - 1] - '0';
        memset(s2, 0, sizeof (s2));
        int len1 = strlen(s1);
        for(int j = 3;j >= 0;j--){
            s1[len1 + j] = (char)('0' + n % 2);
            n /= 2;
        }
    }else if(len % 3 == 2){
        n = (int)(s[len - 2] - '0') * 10 + (int)(s[len - 1] - '0');
        int len1 = strlen(s1);
        for(int j = 6;j >= 0;j--){
            s1[len1 + j] = (char)('0' + n % 2);
            n /= 2;
        }
    }
    printf("%s",s1);
    return 0;
}
