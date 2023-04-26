#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int cnt;
    long long int data[50];
}Vector;

Vector var[20000];
char item[50][10];

Vector calc(int lo, int hi);
int main(){
    int n; scanf("%d", &n); getchar();

    for (int i = 0; i != n; i++){
        int t = 0;
        do{
            char s[201];
            scanf("%s", s);
            strcpy(item[t++], s);
        }while(getchar() != '\n'); 

        Vector ans = calc(0, t-1);

        if (ans.cnt == -1) ans = var[ans.data[0]];

        for (int j = 0; j < ans.cnt; j++)
            printf("%lld%c", ans.data[j], j == ans.cnt - 1? '\n': ' ');
    }
    return 0;
}

Vector ADD(Vector, Vector);
Vector SUB(Vector, Vector);
Vector MUL(Vector, Vector);
Vector compADD(Vector);
Vector compMUL(Vector);
Vector compSUB(Vector);
int isAllNum(int l ,int r);
void deal(int *lo, int *hi);
void operate(Vector* o1, Vector* o2, int idx, int lo, int hi);

Vector calc(int lo, int hi){
    deal(&lo, &hi);
    Vector tmp;
    
    if (isAllNum(lo, hi)){
        tmp.cnt = 0;
        for (int i = lo; i <= hi; i++)
            tmp.data[tmp.cnt++] = atoi(item[i]);
        return tmp;
    }

    if (lo == hi){
        tmp.cnt = -1;
        long long int d = 0;
        for (int i = 0; item[lo][i]; i++)
            d = d * 26 + (item[lo][i] - 'a' + 1);
        tmp.data[0] = d;
        return tmp;
    }

    int j = -1, t = 0;
    for (int i = lo; i <= hi; i++){
        if (!strcmp(item[i], ")")) ++t;
        else if(!strcmp(item[i], "(")) --t;
        else if (t == 0 && i > lo && (!strcmp(item[i], "+") || !strcmp(item[i], "-") || !strcmp(item[i], "=") || !strcmp(item[i], "*")))
            {j = i; break;}
    }

    Vector opera1, opera2;

    if (!strcmp(item[j], "=")){
        opera2 = calc(j+1, hi);
        if (opera2.cnt == -1) opera2 = var[opera2.data[0]];
        opera1 = calc(lo, j-1);
        var[opera1.data[0]] = opera2;
        return opera2;
    }

    if (!strcmp(item[j], "+")){
        operate(&opera1, &opera2, j, lo, hi);
        return ADD(opera1,opera2);
    } 

    if (!strcmp(item[j], "*")){
        operate(&opera1, &opera2, j, lo, hi);
        return MUL(opera1, opera2);
    }

    if (!strcmp(item[j], "-")){
        operate(&opera1, &opera2, j, lo, hi);
        return SUB(opera1, opera2);
    }

    if (!strcmp(item[lo + 1], "/")){
        opera1 = calc(lo+2, hi);
        if (!strcmp(item[lo], "+")) return compADD(opera1);
        if (!strcmp(item[lo], "-")) return compSUB(opera1);
        if (!strcmp(item[lo], "*")) return compMUL(opera1); 
    }
}

void operate(Vector* v1, Vector* v2, int idx, int lo, int hi){
    *v1 = calc(idx+1, hi);
    if ((*v1).cnt == -1) *v1 = var[(*v1).data[0]];
    *v2 = calc(lo, idx-1);
    if ((*v2).cnt == -1) *v2 = var[(*v2).data[0]];
}

void deal(int *lo, int *hi){
    while(1){
        if (strcmp(item[*lo], "(") || strcmp(item[*hi], ")")) return;
        int t = 0;
        for (int i = *lo; i <= *hi; i++){
            if (strcmp(item[i], "(") == 0) ++t;
            else if (strcmp(item[i], ")") == 0) --t;
            else if (t == 0) return;
        }
        ++(*lo), --(*hi);
    }
}

int isNum(char *s){
    return strspn(s, "0123456789") == strlen(s);
}

int isAllNum(int lo, int hi){
    for (int i = lo; i <= hi; i++)
        if (!isNum(item[i])) return 0;
    return 1;
}

Vector ADD(Vector m1, Vector m2){
    Vector tmp;
    if (m1.cnt == 1){
        tmp = m2;
        for (int i = 0; i < m2.cnt; i++)
            tmp.data[i] += m1.data[0];
    }
    else if (m2.cnt == 1){
        tmp = m1;
        for (int i = 0; i < m1.cnt; i++)
            tmp.data[i] += m2.data[0];
    }
    return tmp;
}

Vector SUB(Vector m1, Vector m2){
    Vector tmp;
    if (m1.cnt == 1){
        tmp = m2;
        for (int i = 0; i < m2.cnt; i++)
            tmp.data[i] = m1.data[0] - tmp.data[i];
    }
    else if (m2.cnt == 1){
        tmp = m1;
        for (int i = 0; i != m1.cnt; i++)
            tmp.data[i] -= m2.data[0];
    }
    return tmp;
}

Vector MUL(Vector m1, Vector m2){
    Vector tmp;
    if (m1.cnt == 1){
        tmp = m2;
        for (int i = 0; i != m2.cnt; i++)
            tmp.data[i] *= m1.data[0]; 
    }

    else if (m2.cnt == 1){
        tmp = m1;
        for (int i = 0; i != m1.cnt; i++)
            tmp.data[i] *= m2.data[0];
    }
    return tmp;
}

Vector compADD(Vector m){
    int ID;
    if (m.cnt == -1) {ID = m.data[0]; m = var[m.data[0]];}
    Vector temp = m;
    temp.cnt = 1;
    long long int d = 0;
    for (int i = 0; i < m.cnt; i++)
        d += m.data[i];
    temp.data[0] = d;
    var[ID] = temp;
    return temp;
}

Vector compMUL(Vector m){
    int ID;
    if (m.cnt == -1) {ID = m.data[0]; m = var[m.data[0]];}
    Vector temp = m;
    temp.cnt = 1;
    long long int d = 1;
    for (int i = 0; i < m.cnt; i++)
        d *= m.data[i];
    temp.data[0] = d;
    var[ID] = temp;
    return temp;
}

Vector compSUB(Vector m){
    int ID;
    if (m.cnt == -1){ID = m.data[0]; m = var[m.data[0]];}
    Vector temp = m;
    temp.cnt = 1;
    long long int d = 0;
    for (int i = m.cnt - 1; i >= 0; i--)
        d = m.data[i] - d;
    temp.data[0] = d;
    var[ID] = temp;
    return temp;
}

