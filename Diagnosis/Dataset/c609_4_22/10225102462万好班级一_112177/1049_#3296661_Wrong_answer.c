#include <stdio.h>
#include <string.h>
int main(){
    char tmp[1200];

    gets(tmp);
        int first[600], second[600];
        int ans[600];
        for (int i = 0; i < 600; ++i) {
            first[i] = 0;
            second[i] = 0;
            ans[i] = 0;
        }

        int j = 0;
        int cnt = 599;

        for (; tmp[j] != '\0'; ++j) { if (tmp[j] == ' ')break; }
        for (int i = (int) strlen(tmp) - 1; i > j; --i)second[cnt--] = tmp[i] - '0';
        cnt = 599;
        for (int i = j - 1; i >= 0; --i)first[cnt--] = tmp[i] - '0';


        int flag = 599;
        while (flag >= 0) {
            if (first[flag] - second[flag] < 0) {
                int tmpp = flag - 1;
                while (first[tmpp] == 0) { tmpp--; }
                first[tmpp]--;
                for (int i = tmpp + 1; i < flag; ++i) { first[i] = 9; }
                first[flag] = first[flag] + 10;
            }
            ans[flag] = first[flag] - second[flag];
            flag--;
        }
        int fla = 0;
        for (int i = 0; i < 600; ++i) {
            if (fla == 0 && ans[i] == 0)continue;
            else {
                fla = 1;
                printf("%d", ans[i]);
            }
        }
        printf("\n");
}