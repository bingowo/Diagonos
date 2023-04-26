#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T;
    scanf("%d", &T);
    char s1[81], s2[81], s[81], *pos1, *pos2;
    for(int k=0; k<T; k++){
        scanf("%s%s%s", s1, s2, s);
        pos1 = strstr(s,s1);
        pos2 = strstr(s,s2);
        printf("case #%d:\n", k);
        if(!pos1||!pos2){
            printf("%d\n", 0);
            break;
        }
        while(strstr(pos2+1,s2)) pos2 = strstr(pos2+1,s2); //循环找最后一个
        printf("%d\n", pos2-pos1-strlen(s1));
    }
    return 0;
}