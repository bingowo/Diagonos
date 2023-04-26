#include <stdio.h>
#include <string.h>

char blood[4][3] = {"A","AB","B","O"}, rh[2][2] = {"+","-"};
int type[4][4][4] = {{{1,0,0,1},{1,1,1,0},{1,1,1,1},{1,0,0,1}},\
    {{1,1,1,0}, {1,1,1,0},{1,1,1,0},{1,0,1,0}},\
    {{1,1,1,1},{1,1,1,0},{0,0,1,1},{0,0,1,1}},\
    {{1,0,0,1},{1,0,1,0},{0,0,1,1},{0,0,0,1}}};
int pn[2][2][2] = {{{1,1},{1,1}},{{1,1},{0,1}}};

int input(int* p) {
    char s[4];  scanf("%s",s);
    if(s[0] == '?') return -1;
    *p = s[strlen(s)-1] == '+' ? 0 : 1;
    
    if(s[1] == 'B') return 1;
    else switch(s[0]) {
        case 'A': return 0;
        case 'B': return 2;
        default:  return 3;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0; t<T; ++t) {
        int flag = 0, rf, rm, rc;
        int f = input(&rf), m = input(&rm), c = input(&rc);
        char buf[50] = {0};
        if(c == -1) {
            
            printf("%s%s %s%s ",blood[f],rh[rf],blood[m],rh[rm]);
            for(int i=0; i<4; ++i)
                if(type[f][m][i])
                    for(int j=0; j<2; ++j)
                        if(pn[rf][rm][j]) {
                            if(flag++) strcat(buf, ",");
                            strcat(buf, blood[i]);
                            strcat(buf, rh[j]);
                        }
            if(flag > 1) printf("{%s}\n",buf);
            else printf("%s\n",buf);
        }else if(f == -1) {
            for(int i=0; i<4; ++i)
                if(type[i][m][c])
                    for(int j=0; j<2; ++j)
                        if(pn[j][rm][rc]) {
                            if(flag++) strcat(buf, ",");
                            strcat(buf, blood[i]);
                            strcat(buf, rh[j]);
                        }
            if(flag > 1) printf("{%s}",buf);
            else if(flag) printf("%s",buf);
            else printf("impossible");
            printf(" %s%s %s%s\n",blood[m],rh[rm],blood[c],rh[rc]);
        }else {
            printf("%s%s ",blood[f],rh[rf]);
            for(int i=0; i<4; ++i)
                if(type[f][i][c])
                    for(int j=0; j<2; ++j)
                        if(pn[rf][j][rc]) {
                            if(flag++) strcat(buf, ",");
                            strcat(buf, blood[i]);
                            strcat(buf, rh[j]);
                        }
            if(flag > 1) printf("{%s}",buf);
            else if(flag) printf("%s",buf);
            else printf("impossible");
            printf(" %s%s\n",blood[c],rh[rc]);
        }
    }
    return 0;
}
