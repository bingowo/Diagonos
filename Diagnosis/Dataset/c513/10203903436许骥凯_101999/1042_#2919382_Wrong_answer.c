#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *p1, const void *p2){
    return *(char *)p1 - *(char *)p2;
}

void Print(char *s, char *comb){
    if (*s){
        char left[17] = {0};
        sprintf(left, "%s%c", comb, s[0]);
        printf("%s\n", left);
        Print(s+1, left);
        Print(s+1, comb);
    }
}

int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        char temp[17];
        scanf("%s", temp);
        qsort(temp, strlen(temp), sizeof(temp[0]), cmp);
        
        char s[17]; int len = 0;
        for (int i = 0; i != strlen(temp); i++)
            if (temp[i] != temp[i+1]) s[len++] = temp[i];
        s[len] = 0;
        Print(s, "");
    }
    return 0;
}