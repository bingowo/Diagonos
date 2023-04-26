#include<stdio.h>
#include<string.h>
int main(){
    int n; scanf("%d", &n); getchar();
    char *table[6] = {"the", "a", "an", "of", "for", "and"};
    for (int i = 0; i != n; i++){
        char s[101]; int cnt = 0;
        do{
            int flag = 1;
            scanf("%s", s);
            for (int j = 0; j != 6; j++)
                if (!strcmp(table[j], s)){
                    flag = 0; break;
                }
            if (flag) cnt++;
        }while(getchar() != '\n');
        printf("case #%d:\n%d\n", i, cnt);
    }
}