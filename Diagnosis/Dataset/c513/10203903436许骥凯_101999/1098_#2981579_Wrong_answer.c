#include<stdio.h>
#include<string.h>
int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        int lamp[4] = {0};
        printf("case #%d:\n", i);
        char s[101]; scanf("%s", s); int len = strlen(s); 
        int loc[4] = {-1, -1, -1, -1};
        for (int i = 0; i != len; i++){
            if (s[i] == 'R' && loc[0] == -1) loc[0] = i % 4;
            if (s[i] == 'B' && loc[1] == -1) loc[1] = i % 4;
            if (s[i] == 'Y' && loc[2] == -1) loc[2] = i % 4;
            if (s[i] == 'G' && loc[3] == -1) loc[3] = 1 % 4; 
        }
        for (int i = 0; i != 4; i++){
            if (loc[i] == -1){
                int res = 0;
                for (int i = 0; i != 4; i++){
                    if (loc[i] != -1) res += loc[i];
                }
                loc[i] = 6 - res;
                break;
            }
        }
        for (int i = 0; i != len; i++){
            if (s[i] == '!'){
                if ((i - loc[0]) % 4 == 0) lamp[0]++;
                if ((i - loc[1]) % 4 == 0) lamp[1]++;
                if ((i - loc[2]) % 4 == 0) lamp[2]++;
                if ((i - loc[3]) % 4 == 0) lamp[3]++;
            }
        }
        for (int i = 0; i != 4; i++)
            printf("%d%c", lamp[i], i == 3? '\n': ' ');
    }
    return 0;
}