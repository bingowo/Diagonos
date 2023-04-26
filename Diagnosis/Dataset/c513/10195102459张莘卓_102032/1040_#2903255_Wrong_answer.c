#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char *s) {
    if(strcmp(s, "A")==0) return 0;
    if(strcmp(s, "AB")==0) return 1;
    if(strcmp(s, "B")==0) return 2;
    return 3;
}
int max(char a, char b) {return a>b?a:b;}
int min (char a, char b){return a<b?a:b;}

int main()
{
    char type[4][3] = {"A","AB","B","O"};
    char gen[4][3]  = {"AO","AB","BO","O"};
    char f[3],m[3],c[3];
    scanf("%s %s %s",f,m,c);
    if(strcmp(c, "?")==0) {
        int cnt[4] = {0};
        int i = find(f), j = find(m);
        for(int k1=0; gen[i][k1]; ++k1){
            for(int k2=0; gen[j][k2]; ++k2){
                char a = min(gen[i][k1], gen[j][k2]);
                char b = max(gen[i][k1], gen[j][k2]);
                if(a == 'A'){
                    if(b == 'B') ++cnt[1];
                    else ++cnt[0];
                }else if(a == 'B') ++cnt[2];
                else ++cnt[3];
            }
        }
        int t = 0;
        for(int m=0; m<4; ++m) if(cnt[m]) ++t;
        printf("%s %s {",f,m);
        for(int k=0; k<4; ++k){
            if(cnt[k]){
                printf("%s",type[k]);
                if(--t) printf(",");
            }
        }
        printf("}\n");
    }else{
        int i = strcmp(f,"?") ? find(f) : find(m);
        int j = find(c), cnt[4] = {0};
        if(strcmp(c,"A")==0) {
            if(strchr(gen[i], 'A')){
                cnt[0] = cnt[1] = cnt[2] = cnt[3] = 1;
            }
            if(strchr(gen[i],'O')) {
                cnt[0] = cnt[1] = 1;
            }
        }else if(strcmp(c,"AB")==0){
            if(strchr(gen[i], 'A')){
                cnt[1] = cnt[2] = 1;
            }
            if(strchr(gen[i], 'B')){
                cnt[0] = cnt[1] = 1;
            }
        }else if(strcmp(c,"B")==0){
            if(strchr(gen[i], 'B')){
                cnt[2] = cnt[3] = 1;
            }
            if(strchr(gen[i], 'O')){
                cnt[1] = cnt[2] = 1;
            }
        }else{
            if(strchr(gen[i],'O')) {
                cnt[0] = cnt[2] = cnt[3] = 1;
            }
        }

        if(strcmp(f,"?")) printf("%s ",f);
        int t = 0;
        for(int k=0; k<4; ++k) if(cnt[k]) ++t;
        if(t) {
            printf("{");
            for(int k=0; k<4; ++k)
                if(cnt[k]) {
                    printf("%s",type[k]);
                    if(--t) printf(",");
                }
            printf("} ");
        }else printf("impossible ");
        if(strcmp(m,"?")) printf("%s ",m);
        printf("%s\n",c);
    }
    return 0;
}
