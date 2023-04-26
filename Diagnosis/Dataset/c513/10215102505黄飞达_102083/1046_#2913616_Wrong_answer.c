#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int T;
    scanf("%d ", &T);
    const char *a[7] = {"the", "a", "an", "of", "for", "and"};
    for (int t = 0; t < T; t++){
        char s[101] = {0};
        int count = 0;
        while (1){
            scanf("%s", s);
            int flag = 0;
            for (int i = 0; i < 6; i++){
                if (strcmp(s, a[i])!=0){
                    flag++;
                }
            }
            if (flag==6) count++;
            char ch = getchar();
            if (ch == '\n') {
                printf("case #%d:\n", t);
                printf("%d\n", count); 
                break;
            }   
        }
    }
    return 0;
}