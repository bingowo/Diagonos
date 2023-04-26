#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000000];
    scanf("%s", s);
    int a[62] = {0};  //a数组依次存储A~Z,a~z,0~9
    int num, l = 0, r = strlen(s) - 1, start = 0, count = 0, max = 0;
    for (int i = 0; i < strlen(s); i ++) {
        if (s[i] >= 'A' && s[i] <= 'Z'){
            num = s[i] - 'A';
        }
        else if (s[i] >= 'a' && s[i] <= 'z'){
            num = s[i] - 'a' + 26;
        }
        else {
            num = s[i] - '0' + 52;
        }
        if (a[num] == 0) {
            a[num] ++;
            count ++;
        }
        else {
            for (int j = 0; j < 62; j ++){
                a[j] = 0;
            }
            if (count > max) {
                max = count;
                l = start;
                r = i - 1;
            }
            count = 1;
            a[num] = 1;
            start = i;
        }
    }
    for (int i = l; i <= r; i ++){
        printf("%c", s[i]);
    }
    return 0;
}