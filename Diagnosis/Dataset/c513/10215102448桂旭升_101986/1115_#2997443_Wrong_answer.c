#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp1(const void *pa, const void *pb){
    char a = *(char *)pa, b = *(char*)pb;
    return a > b ? -1 : 1;
}
int cmp2(const void *pa, const void *pb){
    char a = *(char *)pa, b = *(char*)pb;
    return a < b ? -1 : 1;
}
int main(){
	int len, t, flag, i, j, index, k;
    char s[21] = {0};
    char temp[21] = {0};
    scanf("%d", &t);
    for(k = 0; k < t; k++){
        flag = 0;
        scanf("%s", s);
        len = strlen(s);
        char min = '9' + 1;
        int mi = 0;
        for(i = len - 2; i >= 0; i--){
            j = i + 1;
            for(; j < len; j++){
                if(s[j] > s[i] && s[j] < min){
                    min = s[j]; mi = j;
                    flag = 1;
                }
            }
            if(flag){
                s[mi] = s[i];
                s[i] = min;
                break;
            }
        }
        index = i; j = 0;
        printf("case #%d:\n", k);
        for(i = 0; i <= index; i++){
            printf("%c", s[i]); s[i] = '0';
        }
        for(;i < len; i++){
            temp[j++] = s[i];
        }
        temp[j] = '\0';
        qsort(temp, len - 1 - index, sizeof(char), cmp2);
        printf("%s\n", temp);
    }
    system("pause");
	return 0;
}