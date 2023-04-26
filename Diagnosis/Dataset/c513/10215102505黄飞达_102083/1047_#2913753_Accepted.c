#include<stdio.h>
#include<string.h>

int main(){
    int T;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++){
        char s[505] = {0};
        gets(s);
        printf("case #%d:\n", t);
        for (int i = 0; i < strlen(s); i++){
            int count = 1;
            for (int j = 1; j <= 255; j++){
                if (j==255) {
                    printf("255%c", s[i]);
                    i += 254;
                    break;
                }
                if (s[i] == s[i+j]) count++;
                else if (s[i]!= s[i+j]) {
                    i += j-1;
                    printf("%d%c", count, s[i]);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}