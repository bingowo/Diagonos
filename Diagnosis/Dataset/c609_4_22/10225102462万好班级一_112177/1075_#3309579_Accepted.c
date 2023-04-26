#include <stdio.h>

int main() {
    char s[80];
    while(scanf("%s",s) != EOF){
        char ans[160][80];

        for (int i = 0; i < 160; ++i) {
            for (int j = 0; j < 80; ++j) {
                ans[i][j] = ' ';
            }
        }
        int hang = 80;ans[hang][0] = s[0];
        int h_max = 80;
        int h_min = 80;
        for (int i = 1;s[i] != '\0';++i) {
            if(s[i] < s[i-1])ans[++hang][i] = s[i];
            else if(s[i] > s[i-1])ans[--hang][i] = s[i];
            else ans[hang][i] = s[i];

            if(hang > h_max)h_max = hang;
            if(hang < h_min)h_min = hang;
        }

        for (int i = h_min; i <= h_max; ++i) {
            for (int j = 0; j < 80; ++j) {
                printf("%c",ans[i][j]);
            }printf("\n");
        }
    }
}
