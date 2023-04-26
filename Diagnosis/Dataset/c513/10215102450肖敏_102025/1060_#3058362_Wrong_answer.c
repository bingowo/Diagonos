#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    scanf("%s", s);
    int len = strlen(s);
    int num[130], sum = 1;
    for (int i = 0; i < len; i++) {
        memset(num, 0, sizeof(num));
        int count = 0;
        int j = i;
        while (s[j] >= '1' && s[j] <= '9' && num[s[j]] == 0) {
            count++;
            num[s[j]]++;
            j++;
        }
        if (sum < count) {
            sum = count;
        }
    }
    printf("%d\n",sum);
    return 0;
}
