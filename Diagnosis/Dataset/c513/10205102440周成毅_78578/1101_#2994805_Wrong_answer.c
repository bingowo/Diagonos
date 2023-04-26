#include <stdio.h>
#include <string.h>

const int ABO[4][4][4] = {1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1,
                          0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0,
                          0, 1};

const int Rh[2][2][2] = {1, 1, 1, 1, 1, 1, 0, 1};

typedef struct {
    int abo, rh, isn;
} peo;

void read(peo *a, char *s) {
    if (!strcmp(s, "AB+")) {
        a->abo = 1;
        a->isn = 0;
        a->rh = 0;
    } else if (!strcmp(s, "A+")) {
        a->abo = 0;
        a->isn = 0;
        a->rh = 0;
    } else if (!strcmp(s, "B+")) {
        a->abo = 2;
        a->isn = 0;
        a->rh = 0;
    } else if (!strcmp(s, "O+")) {
        a->abo = 3;
        a->isn = 0;
        a->rh = 0;
    } else if (!strcmp(s, "AB-")) {
        a->abo = 1;
        a->isn = 0;
        a->rh = 1;
    } else if (!strcmp(s, "A-")) {
        a->abo = 0;
        a->isn = 0;
        a->rh = 1;
    } else if (!strcmp(s, "B-")) {
        a->abo = 2;
        a->isn = 0;
        a->rh = 1;
    } else if (!strcmp(s, "O-")) {
        a->abo = 3;
        a->isn = 0;
        a->rh = 1;
    } else {
        a->abo = -1;
        a->isn = 1;
        a->rh = -1;
    }
}

int ans_abo[4], ans_rh[2];

char AB_BLOOD[][3] = {"A", "AB", "B", "O"};
char RH_BLOOD[][2] = {"+", "-"};

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(ans_rh, 0, sizeof(ans_rh));
        memset(ans_abo, 0, sizeof(ans_abo));
        char f[5],m[5],e[5];
        peo fa, ma, er;
        scanf("%s %s %s",f,m,e);
        read(&fa,f);
        read(&ma,m);
        read(&er,e);
        if (fa.isn) {
            for (int i = 0; i < 4; i++)
                ans_abo[i] = ABO[i][ma.abo][er.abo];
            for (int i = 0; i < 2; i++)
                ans_rh[i] = Rh[i][ma.rh][er.rh];
            int kuohao = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    if (ans_abo[i] && ans_rh[j]) {
                        if (!kuohao) {
                            printf("{");
                            kuohao = 1;
                            printf("%s%s",AB_BLOOD[i],RH_BLOOD[j]);
                        } else{
                            printf(",%s%s",AB_BLOOD[i],RH_BLOOD[j]);
                        }
                    }
                }
            }
            if(kuohao)
                printf("} ");
            else
                printf("impossible ");
            printf("%s %s\n",m,e);
        } else if (ma.isn) {
            for (int i = 0; i < 4; i++)
                ans_abo[i] = ABO[fa.abo][i][er.abo];
            for (int i = 0; i < 2; i++)
                ans_rh[i] = Rh[fa.rh][i][er.rh];
            printf("%s ",f);
            int kuohao = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    if (ans_abo[i] && ans_rh[j]) {
                        if (!kuohao) {
                            printf("{");
                            kuohao = 1;
                            printf("%s%s",AB_BLOOD[i],RH_BLOOD[j]);
                        } else{
                            printf(",%s%s",AB_BLOOD[i],RH_BLOOD[j]);
                        }
                    }
                }
            }
            if(kuohao)
                printf("} ");
            else
                printf("impossible ");
            printf("%s\n",e);
        } else {
            for (int i = 0; i < 4; i++)
                ans_abo[i] = ABO[fa.abo][ma.abo][i];
            for (int i = 0; i < 2; i++)
                ans_rh[i] = Rh[fa.rh][ma.rh][i];
            printf("%s %s ",f,m);
            int kuohao = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    if (ans_abo[i] && ans_rh[j]) {
                        if (!kuohao) {
                            printf("{");
                            kuohao = 1;
                            printf("%s%s",AB_BLOOD[i],RH_BLOOD[j]);
                        } else{
                            printf(",%s%s",AB_BLOOD[i],RH_BLOOD[j]);
                        }
                    }
                }
            }
            if(kuohao)
                printf("}\n");
            else
                printf("impossible\n");
        }
    }
    return 0;
}
