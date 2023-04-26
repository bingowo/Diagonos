#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T, max=0;
    scanf("%d", &T);
    char s1[81], s2[81], s[81], *pos1, *pos2;
    for(int k=0; k<T; k++){
        scanf("%s%s%s", s1, s2, s);
        max = 0;
        printf("case #%d:\n", k);
        pos1 = strstr(s,s1); //s1为第一个
        pos2 = strstr(s,s2);
        if(!pos1||!pos2){
            printf("%d\n", 0);
            continue;
        }
        while(strstr(pos2+1,s2))
            pos2 = strstr(pos2+1,s2); //循环找最后一个s2
        if(pos2>pos1+strlen(s1)-1) max = pos2-pos1-strlen(s1);
        else if(pos1>pos2+strlen(s2)-1) max = pos1-pos2-strlen(s2);
        pos2 = strstr(s,s2); //s2为第一个
        while(strstr(pos1+1,s1))
            pos1 = strstr(pos1+1,s1); //循环找最后一个s1
        if(pos2>pos1+strlen(s1)-1){
            if(pos2-pos1-strlen(s1)>max)
                max = pos2-pos1-strlen(s1);
        }
        else if(pos1>pos2+strlen(s2)-1){
            if(pos1-pos2-strlen(s2)>max)
                max = pos1-pos2-strlen(s2);
        }
        printf("%d\n", max);
    }
    return 0;
}