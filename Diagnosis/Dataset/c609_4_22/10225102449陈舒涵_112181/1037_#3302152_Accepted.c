#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000000];
    scanf("%s", s);
    int n = strlen(s);
    int a[62];  //a数组依次存储该字符上一次出现的位置，顺序为A~Z，a~z，0~9
    for (int j = 0; j < 62; j ++){
        a[j] = -1;
    }
    int num, l = 0, r = n - 1, start = 0, count = 0, max = 0;
    int i = 0;
    while (i < n) {
        if (s[i] >= 'A' && s[i] <= 'Z'){
            num = s[i] - 'A';
        }
        else if (s[i] >= 'a' && s[i] <= 'z'){
            num = s[i] - 'a' + 26;
        }
        else {
            num = s[i] - '0' + 52;
        }
        if (a[num] < start || i == 0) {  //当前字符串中没有出现过该字符
            a[num] = i;
            count ++;
        }
        else {  //当前字符串中出现过该字符
            if (count > max) {
                max = count;
                l = start;
                r = i - 1;
            }
            start = a[num] + 1;
            a[num] = i;
            count = i - start + 1;
        }
        i ++;
    }
    if (count > max) {
                max = count;
                l = start;
                r = n - 1;
    }
    for (int j = l; j <= r; j ++){
        printf("%c", s[j]);
    }
    return 0;
}