#include <stdio.h>
#include <ctype.h>

void sic_1(char*);void sic_2(char*);
int i_s1[52] = {0},i_s2[52] = {0};

int main() {
   char s1[52],s2[53];
    while(scanf("%s",s1) != EOF){
       scanf("%s",s2);
        for (int i = 0; i < 52; ++i) i_s1[i] = 0;
        for (int i = 0; i < 52; ++i) i_s2[i] = 0;

        sic_1(s1);sic_2(s2);

        int answer[52] = {0};

        for (int i1 = 52; i1 >= 0; --i1) {if(i_s1[i1] == 0)continue;
            for (int i2 = 52; i2 >= 0; --i2) {if(i_s2[i2] == 0)continue;
                answer[i1+i2] = answer[i1+i2] + i_s1[i1]*i_s2[i2];}}

        for (int i = 51; i >= 0 ; --i) {
            if(answer[i] == 0)continue;
            printf("%d ",answer[i]);}printf("\n");
    }

}
void sic_1(char* s){
    for (int i = 0;s[i] != '\0'; ++i) {
        int tmp = 0;int flag = 0;int sick = 0;int cnt = 0;
        if(s[i] == '-'){flag++;i++;}if(s[i] == '+')i++;
        while(isdigit(s[i])){tmp = tmp*10 + (s[i] - '0');i++;}
        if(flag == 1)tmp = -tmp;
        if(s[i] == 'x'){cnt++;sick++;if(s[i+1] == '^'){int p = i+2;sick = 0;while(isdigit(s[p])){sick = sick*10 + (s[p] - '0');p++;}i = p-1;}}
        if(tmp)i_s1[sick] = tmp;else i_s1[sick] = 1;
        if(!cnt)break;
    }
}


void sic_2(char* s){
    for (int i = 0;s[i] != '\0'; ++i) {
        int tmp = 0;int flag = 0;int sick = 0;int cnt = 0;
        if(s[i] == '-'){flag++;i++;}if(s[i] == '+')i++;
        while(isdigit(s[i])){tmp = tmp*10 + (s[i] - '0');i++;}
        if(flag == 1)tmp = -tmp;
        if(s[i] == 'x'){cnt++;sick++;if(s[i+1] == '^'){int p = i+2;sick = 0;while(isdigit(s[p])){sick = sick*10 + (s[p] - '0');p++;}i = p-1;}}
        if(tmp)i_s2[sick] = tmp;else i_s2[sick] = 1;
        if(!cnt)break;
    }
}