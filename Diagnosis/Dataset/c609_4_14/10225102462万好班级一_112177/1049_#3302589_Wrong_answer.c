#include <stdio.h>
#include <string.h>

int first[600], second[600];int ans[600];char f[600],s[600];

int cmp(char* a,char* b){
    if(strlen(a) > strlen(b))return 0;
    else if(strlen(a) < strlen(b)) return 1;
    else return strcmp(f,s)< 0;
}

int main(){
    while(scanf("%s %s",f,s) != EOF){
        if(strcmp(f,s) == 0){printf("0");continue;}
        int cnt = 599;
        for (int i = 0; i < 600; ++i) {
            first[i] = 0;
            second[i] = 0;
            ans[i] = 0;
        }
        if(cmp(f,s)){char tmp[600];strcpy(tmp,f);strcpy(f,s);strcpy(s,tmp);}
        for (int i = (int)strlen(f)-1;i >= 0; --i) {
            first[cnt--] = f[i] - '0';
        }
        cnt = 599;
        for (int i = (int)strlen(s)-1;i >= 0; --i) {
            second[cnt--] = s[i] - '0';
        }

        int flag = 599;
        while (flag >= 0) {
            if (first[flag] - second[flag] < 0) {
                int tmpp = flag - 1;
                while (first[tmpp] == 0) { tmpp--; }
                first[tmpp]--;
                for (int i = tmpp + 1; i < flag; ++i) { first[i] = 9; }
                first[flag] = first[flag] + 10;
            }
            ans[flag] = first[flag] - second[flag];
            flag--;
        }
        int fla = 0;
        for (int i = 0; i < 600; ++i) {
            if (fla == 0 && ans[i] == 0)continue;
            else {
                fla = 1;
                printf("%d", ans[i]);
            }
        }
        printf("\n");
    }
}