#include <stdio.h>
#include <string.h>

char blood[4][3] = {"A","AB","B","O"};
    int type[4][4][4] = {{{1,0,0,1},{1,1,1,0},{1,1,1,1},{1,0,0,1}},\
        {{1,1,1,0}, {1,1,1,0},{1,1,1,0},{1,0,1,0}},\
        {{1,1,1,1},{1,1,1,0},{0,0,1,1},{0,0,1,1}},\
        {{1,0,0,1},{1,0,1,0},{0,0,1,1},{0,0,0,1}}};

int input(void) {
    int flag = -1;
    char s[3]; scanf("%s",s);
    if(strcmp(s, "AB") == 0) flag = 1;
    else switch(s[0]) {
        case 'A': flag = 0; break;
        case 'B': flag = 2; break;
        case 'O': flag = 3; break;
    }
    return flag;
}



int main()
{
    int flag = 0;
    int f = input(), m = input(), c = input();
    if(c == -1) {
        printf("%s %s {",blood[f],blood[m]);
        for(int i=0; i<4; ++i) {
            if(type[f][m][i]) {
                if(flag) printf(",");
                printf("%s",blood[i]);
                flag = 1;
            }
        }
        printf("}\n");
    }else if(f == -1) {
        for(int i=0; i<4; ++i) {
            if(type[i][m][c]) {
                if(flag) printf(",");
                else{
                    printf("{");
                    flag = 1;
                }
                printf("%s",blood[i]);
            }
        }
        printf("%s",flag ? "}" : "impossible");
        printf(" %s %s\n",blood[m],blood[c]);
    }else {
        printf("%s ",blood[f]);
        for(int i=0; i<4; ++i) {
            if(type[f][i][c]) {
                if(flag) printf(",");
                else {
                    flag = 1;
                    printf("{");
                }
                printf("%s",blood[i]);
            }
        }
        printf("%s",flag ? "}" : "impossible");
        printf(" %s\n",blood[c]);
    }
    return 0;
}