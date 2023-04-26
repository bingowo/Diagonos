#include<stdio.h>
#include<string.h>

int main(){
    int T; scanf("%d", &T);
    for (int i = 0; i != T; ++i){
        printf("case #%d:\n", i);
        char s[51]; scanf("%s", s);
        int res[150] = {0}; int len = 0;
        for (int j = strlen(s) - 1; j > 1; --j){
            int idx = 0;
            int temp = (s[j] - '0') * 10 + res[idx];
            do{
                res[idx++] = temp / 8;
                temp = (temp % 8) * 10 + res[idx];
            }while(temp || idx < len);
            len = idx;
        }
        printf("0.");
        for (int j = 0; j != len; ++j)
            printf("%d", res[j]);
        printf("\n");
    }
    return 0;
}