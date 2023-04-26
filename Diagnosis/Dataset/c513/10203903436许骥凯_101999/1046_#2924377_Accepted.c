#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char* trans(const char *s){
    int len = strlen(s);
    char *temp = (char*)malloc(sizeof(char) * len);
    for (int i = 0; i != len; i++)
        temp[i] = isalpha(s[i])? tolower(s[i]): s[i];
    temp[len] = 0;
    return temp;
}
int main(){
    int n; scanf("%d", &n); getchar();
    char *table[6] = {"the", "a", "an", "of", "for", "and", };
    for (int i = 0; i != n; i++){
        char s[101]; int cnt = 0;
        do{
            int flag = 1; char *p;
            scanf("%s", s); p = trans(s);
            for (int j = 0; j != 6; j++)
                if (!strcmp(table[j], p)){
                    flag = 0; break;
                }
            free(p);
            if (flag) cnt++;
        }while(getchar() != '\n');
        printf("case #%d:\n%d\n", i, cnt);
    }
}