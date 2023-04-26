#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check(char s[], char time[]){
    char s0[20] = {0};
    strncpy(s0, s, 6);
    if (strcmp(s0, "$GPRMC") == 0){
        char *p = strstr(s, ",");
        int index = p-s;
        for (int i=0; s[i]!=','; i++) time[i] = s[index+i+1];
        p = strstr(s+index+1, ",");
        index = p-s;
        char zhuangtai = s[index+1];
        if (zhuangtai == 'A'){
            p = strstr(s, "*");
            index = p-s;
            int slen = strlen(s), num = 0, ans = s[1];
            for (int i = index+1; i < slen; i++){
                num *= 16;
                if (isdigit(s[i])) num += s[i]-'0';
                else {
                    if ('a'<=s[i]&&s[i]<='z') s[i] = s[i]-'a'+'A';
                    num += s[i]-'A'+10;
                }
            }
            for (int i = 2; i < index; i++) {
                ans^=s[i];
            }
            if (ans == num) return 1;
        }   
    }   
    return 0;
}

int main(){
    char s[10000] = {0}, time[11] = {0};
    int hh = 0;
    while (strcmp(s, "END") != 0 && s != NULL){
        fgets(s, 10000, stdin);
        int slen = strlen(s);
        s[slen-1] = '\0';
        // gets(s);
        if (check(s, time)==1){
            hh = (time[0]-'0')*10+time[1]-'0'+8;
            if (hh>24) hh -= 24;
        }          
    }
    printf("%02d:%c%c:%c%c\n", hh,time[2],time[3],time[4],time[5]);
    return 0;
}
