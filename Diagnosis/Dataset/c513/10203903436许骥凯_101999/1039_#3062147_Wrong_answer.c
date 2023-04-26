#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_VAR 26*26*26+26*26+27


typedef struct{
    long long v[150];
    int cnt;
}vector;

vector table[MAX_VAR];


void Init(){
    for (int i = 0; i != MAX_VAR; ++i)
        table[i].cnt = 0;
}
void Print(char (*s)[20], int len){
    for (int i = 0; i != len; ++i)
        printf("%s\n", s[i]);
}

void Print_vec(vector res){
    for (int j = 0; j != res.cnt; ++j)
        printf("%lld%c", res.v[j], j == res.cnt - 1? '\n': ' ');
}

int cal_Hash(char *s){
    int res = 0;
    for (; *s; ++s)
        res = res * 26 + (*s - 'a' + 1);
    return res;
}

void add_var(char *s, vector vec){
    int hash_value = cal_Hash(s);
    table[hash_value].cnt = vec.cnt;
    for (int i = 0; i != vec.cnt; ++i)
        table[hash_value].v[i] = vec.v[i];
}

void deal(char (*s)[20], int *lo, int *hi){
    if (s[*lo][0] != '(') return;
    int cnt = 1;
    for (int i = *lo + 1; i != *hi - 1; ++i){
        if (s[i][0] == '(') ++cnt;
        else if (s[i][0] == ')') --cnt;
        if (cnt == 0) return;
    }
    ++*lo;
    --*hi;
}

vector assign(char *s, vector vec){
    add_var(s, vec);

    // test
    //Print_vec(table[cal_Hash(s)]);
    // end

    return vec;
}

vector add_sub_mult(vector vt, vector vec, char op){
    for (int i = 0; i != vt.cnt; ++i){
        switch (op){
            case '*':
                vt.v[i] *= vec.v[0]; break;
            case '+':
                vt.v[i] += vec.v[0]; break;
            case '-':
                vt.v[i] -= vec.v[0]; break;
            default:
                printf("operate error\n"); break;
        }
    }
    return vt;    
}



vector div_sep(char *s, char op){
    vector vt = table[cal_Hash(s)];
    for (int i = 1; i != vt.cnt; ++i){
        switch (op)
        {
        case '*':
            vt.v[0] *= vt.v[i];
            break;
        case '+':
            vt.v[0] += vt.v[i];
            break;
        case '-':
            vt.v[vt.cnt - i - 1] = vt.v[vt.cnt - i - 1] - vt.v[vt.cnt - i];
            break;
        default:
            break;
        }
    }
    vt.cnt = 1;
    return vt;
}

vector cal_exp(char (*s)[20], int lo, int hi);
vector resolute_brak(char (*s)[20], int lo, int hi){
    int cnt = 0, i = lo;
    while(i != hi){
        if (s[i][0] == '(') ++cnt;
        else if (s[i][0] == ')') --cnt;
        if (cnt == 0) break;
        ++i;
    }
    if (s[i + 1][0] == '-'){
        vector temp = cal_exp(s, i + 2, hi);
        vector temp_2 = cal_exp(s , lo , i + 1);
        return add_sub_mult(temp_2, temp, s[i + 1][0]);
    }
    return add_sub_mult(cal_exp(s, i + 2, hi), cal_exp(s, lo, i + 1), s[i + 1][0]);
}

vector cal_exp(char (*s)[20], int lo, int hi){
    deal(s, &lo, &hi);
    if (s[lo][0] == '('){
        return resolute_brak(s, lo, hi);       
    }else if (isalpha(s[lo][0])){
        char var[4];
        strcpy(var, s[lo]);
        ++lo;
        if (lo == hi){
            return table[cal_Hash(var)];
        }else if (s[lo][0] == '='){
            return assign(var, cal_exp(s, lo + 1, hi));
        }else{
            return add_sub_mult(table[cal_Hash(var)], cal_exp(s, lo + 1, hi), s[lo][0]);
        }
    }else if (isdigit(s[lo][0])){
        vector temp;
        int i = 1;
        while((lo + i < hi) && isdigit(s[lo + i][0])) ++i;
        temp.cnt = i;
        for (i = 0; i != temp.cnt; ++i)
            temp.v[i] = atoll(s[lo + i]);
        if (lo + i == hi) return temp;
        else
            return add_sub_mult(temp, cal_exp(s, lo + i + 1, hi), s[lo + i][0]);
        
    }
    else{
        int i = lo;
        lo += 2;
        char var[4];
        strcpy(var, s[lo]);
        return div_sep(var, s[i][0]);
    }   
}




int main(){
    Init();
    int N; scanf("%d", &N); getchar();
    for (int i = 0; i != N; ++i){
        char c;
        char s[150][20]; int slen = 0;
        do{
           scanf("%s", s[slen++]);
        }while((c = getchar()) != '\n');
        //test
        //Print(s, slen);
        //end
        vector res = cal_exp(s, 0, slen);
        for (int j = 0; j != res.cnt; ++j)
            printf("%lld%c", res.v[j], j == res.cnt - 1? '\n': ' ');
    }
    return 0;
}
