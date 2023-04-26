#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct{
    long long v[150];
    int cnt;
}vector;

#define MAX_TABLE_LEN 26 * 26 * 26 + 26 * 26 + 26
vector table[MAX_TABLE_LEN];

int cal_hash(char *s){
    int res = 0;
    for (; *s; ++s)
        res = 26 * res + (*s - 'a' + 1);        // +1防止 a 、aa、aaa 映射到相同值 0
    return res;
}

void add_hash(char *s, vector v){
    int h_v = cal_hash(s);
    table[h_v] = v;
}

void deal(char (*s)[20], int *lo, int *hi){
    if (s[*lo][0] != '(') return ;                // 第一位不为(则直接返回
    int cnt = 1;                                    
    for (int i = *lo + 1; i != *hi - 1; ++i){     // 匹配到最后一个括号之前
        if (s[i][0] == '(') ++cnt;
        else if (s[i][0] == ')') --cnt;
        if (cnt == 0) return;
    }
    ++*lo, --*hi;
}

vector assign(char *s, vector vec){
    add_hash(s, vec);
    return vec;
}

vector add_sub_mult(vector left, vector right, char op){
    for (int i = 0; i != left.cnt; ++i){
        switch (op)
        {
        case '+': 
            left.v[i] += right.v[0];            // 题目已给出不会有向量与向量的运算
            break;
        case '-':
            left.v[i] -= right.v[0];
            break;
        case '*':
            left.v[i] *= right.v[0];
            break;
        default:
            break;
        }
    }
    return left;
}

vector ope_div(char *s, char op){                           //该操作需要改变table值
    for (int i = 1; i != table[cal_hash(s)].cnt; ++i){
        switch (op)
        {
        case '*':
            table[cal_hash(s)].v[0] *= table[cal_hash(s)].v[i];
            break;
        case '+':
            table[cal_hash(s)].v[0] += table[cal_hash(s)].v[i];
            break;
        case '-':
            table[cal_hash(s)].v[table[cal_hash(s)].cnt - i - 1] = table[cal_hash(s)].v[table[cal_hash(s)].cnt - i - 1] - table[cal_hash(s)].v[table[cal_hash(s)].cnt - i];
            break;
        default:
            break;
        }
    }
    table[cal_hash(s)].cnt = 1;
    return table[cal_hash(s)];
}

vector cal_exp(char (*s)[20], int lo, int hi);
vector resolute_brak(char (*s)[20], int lo, int hi){     // 处理类似(a + b) + b的情况
    int cnt = 1, i = lo + 1;
    for (; i != hi; ++i){
        if (s[i][0] == '(') ++cnt;
        else if (s[i][0] == ')') --cnt;
        if (cnt == 0) break;
    }
    vector right = cal_exp(s, i + 2, hi);              // 按照规定运算顺序，需先计算右边表达式再计算左边
    vector left = cal_exp(s, lo, i + 1);
    return add_sub_mult(left, right, s[i + 1][0]);
}

vector cal_exp(char (*s)[20], int lo, int hi){   // 范围为[lo, hi)
    deal(s, &lo, &hi);                           // 去除最外端括号
    if (s[lo][0] == '('){                        // 处理类似于 (a + b) + c的情况
        return resolute_brak(s, lo, hi);                // 将( a + b ) + c 分解为 cal_exp(a + b) + cal_exp(c)  
    }
    else if (isalpha(s[lo][0])){                // 开头为变量
        if (lo + 1 == hi) 
            return table[cal_hash(s[lo])];    // 类似于 a 的情况，直接返回变量 a 中存储的值
        else if (s[lo + 1][0] == '+' || s[lo + 1][0] == '-' || s[lo + 1][0] == '*'){    // a + b
            vector right = cal_exp(s, lo + 2, hi);
            vector left = cal_exp(s, lo, lo + 1);
            return add_sub_mult(left, right,  s[lo + 1][0]);
        }
        else if (s[lo + 1][0] == '=')                                                   // a = 1
            return assign(s[lo], cal_exp(s, lo + 2, hi));
    }
    else if (isdigit(s[lo][0])){                                                        // 1 2 3 4
        vector temp;
        int i = 0;
        while(lo < hi && isdigit(s[lo + i][0])){
            temp.v[i] = atoll(s[lo + i]);
            ++i;
        }
        temp.cnt = i;
        return temp;
    }
    else if (s[lo + 1][0] == '/'){                                                      // - / a
        return ope_div(s[lo + 2], s[lo][0]);                   
    }
    else{
        printf("error");
        vector temp;
        temp.cnt = 0;
        return temp;
    }
}

int main(){
    int N; scanf("%d", &N); getchar();
    for (int i = 0; i != N; ++i){
        char c;
        char s[150][20]; int slen = 0;
        do{
           scanf("%s", s[slen++]);
        }while((c = getchar()) != '\n');
        vector res = cal_exp(s, 0, slen);
        for (int j = 0; j != res.cnt; ++j)
            printf("%lld%c", res.v[j], j == res.cnt - 1? '\n': ' ');
    }
    return 0;
}