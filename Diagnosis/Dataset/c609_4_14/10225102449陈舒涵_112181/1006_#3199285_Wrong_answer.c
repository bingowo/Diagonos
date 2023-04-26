#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T, count, sum, k;
    scanf("%d", &T);
    int num[60] = {1,0};
    for (int i = 2; i < 60; i ++){
        num[i] = i;
    }
    for (int t = 0; t < T; t ++){
        count = 0;
        sum = 0;
        char s[61];
        scanf("%s", s);
        int a[62];
        for (int i = 0; i < 62; i ++){
            a[i] = -1;
        }
        for (int i = 0; i < strlen(s); i ++){
            if (s[i] >= '0' && s[i] <= '9'){
                k = s[i] - '0';
            }
            else{
                k = (s[i] - 'A') / 32 * 26 + (s[i] - 'A') % 32 + 10;
            }
            if (a[k] == -1){
                a[k] = num[count];
                count ++;
            }
        }
        for (int i = 0; i < strlen(s); i ++){
            if (s[i] >= '0' && s[i] <= '9'){
                k = s[i] - '0';
            }
            else{
                k = (s[i] - 'A') / 32 * 26 + (s[i] - 'A') % 32 + 10;
            }
            sum = sum * count + a[k];
        }
        printf("case #%d:\n%d\n", t, sum);
    }
    return 0;
}