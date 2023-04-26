#include<stdio.h>
#include<string.h>

int Blood[4][4][4] = {
    {
        {1, 0, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}, {1, 0, 0, 1}
    },
    {
        {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 0}, {1, 0, 1, 0}
    },
    {
        {1, 1, 1, 1}, {1, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}
    },
    {
        {1, 0, 0, 1}, {1, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}
    }
};

int blood_to_idx[150];
char idx_to_blood[4][3];

void Init(){
    blood_to_idx['A'] = 0, blood_to_idx['A' + 'B'] = 1, blood_to_idx['B'] = 2, blood_to_idx['O'] = 3;
    strcpy(idx_to_blood[0], "A"), strcpy(idx_to_blood[1], "AB");
    strcpy(idx_to_blood[2], "B"), strcpy(idx_to_blood[3], "O");
}

int cal_hash(char *s){
    int res = 0;
    while(*s) res += *s++;
    return res; 
}

void cal_fa(char* mo, char* so){
    int m_idx = blood_to_idx[cal_hash(mo)], s_idx = blood_to_idx[cal_hash(so)];
    int fa[4], f_idx = 0;
    for (int i = 0; i != 4; ++i)
        if (Blood[i][m_idx][s_idx])
            fa[f_idx++] = i;
    if (f_idx == 0)
        printf("impossible");
    else{
        printf("{");
        for (int i = 0; i != f_idx; ++i)
            printf("%s%c", idx_to_blood[fa[i]], i == f_idx - 1? '}': ',');
    }
    printf(" %s %s\n", mo, so);
}

void cal_mo(char *fa, char *so){
    int f_idx = blood_to_idx[cal_hash(fa)], s_idx = blood_to_idx[cal_hash(so)];
    int mo[4], m_idx = 0;
    for (int i = 0; i != 4; ++i)
        if (Blood[f_idx][i][s_idx])
            mo[m_idx++] = i;
    printf("%s ", fa);
    if (m_idx == 0)
        printf("impossible");
    else{
        printf("{");
        for (int i = 0; i != m_idx; ++i)
            printf("%s%c", idx_to_blood[mo[i]], i == m_idx - 1? '}': ',');
    }
    printf(" %s\n", so);
}

void cal_so(char *fa, char *mo){
    int f_idx = blood_to_idx[cal_hash(fa)], m_idx = blood_to_idx[cal_hash(mo)];
    int so[4], s_idx = 0;
    for (int i = 0; i != 4; ++i)
        if (Blood[f_idx][m_idx][i])
            so[s_idx++] = i;
    printf("%s %s ", fa, mo);
    if (s_idx == 0)
        printf("impossible\n");
    else{
        printf("{");
        for (int i = 0; i != s_idx; ++i)
            printf("%s%c", idx_to_blood[so[i]], i == s_idx - 1? '}': ',');
        printf("\n");
    }
}


int main(){
    Init();
    char fa[3], mo[3], so[3]; scanf("%s %s %s", fa, mo, so);
    if (!strcmp(fa, "?")) cal_fa(mo, so);
    else if (!strcmp(mo, "?")) cal_mo(fa, so);
    else if (!strcmp(so, "?")) cal_so(fa, mo);
    return 0;
}