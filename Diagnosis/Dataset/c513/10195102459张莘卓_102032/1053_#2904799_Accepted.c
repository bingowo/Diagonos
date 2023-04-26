#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int judgeValue(char *s){
    int ans = 0;
    for(char* p=strrchr(s, '*')+1; *p; ++p) {
        if(isdigit(*p))
            ans = ans * 16 + *p - '0';
        else
            ans = ans * 16 + *p - 'A' + 10;
    }
    return ans;
}

int main()
{
    char s[100], ans[100];
    while(scanf("%s",s)) {
        if(strcmp(s, "END")==0) break;
        char t[11]; int i = 0;
        for(; s[i]!=','; ++i) t[i] = s[i];
        t[i++] = '\0';
        if(strcmp(t, "$GPRMC")) continue;
        while(s[i] != ',') ++i;
        if(s[i+1] != 'A') continue;
        int sum = (int) 'G';
        for(char* p=strchr(s, 'P'); *p!='*'; ++p)
            sum ^= *p;
        if(sum % 65536 == judgeValue(s))
            strcpy(ans, s);
    }
    int i = 1;
    while(ans[i-1] != ',') ++i;
    for(int m=0; m<3; ++m, i+=2) {
        int time = (ans[i]-'0')*10 + (ans[i+1]-'0');
        if(ans[i-1] == ',') time = (time+8) % 24;
        else printf(":");
        printf("%02d",time);
    }
    printf("\n");
    return 0;
}
