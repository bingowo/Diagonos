#include <stdio.h>
#include <string.h>

typedef struct {
    int cnt;
    long long data[50];
} vector;

vector var[20000];
char item[50][10];

vector compMUL(vector m1) {
    int ID;
    if (m1.cnt == -1) {
        ID = m1.data[0];
        m1 = var[m1.data[0]];
    }
    vector tmp = m1;
    tmp.cnt = 1;
    long long d = 1;
    for (int i = 0; i < m1.cnt; i++)
        d *= m1.data[i];
    tmp.data[0] = d;
    var[ID] = tmp;
    return tmp;
}

vector compSUB(vector m1) {
    int ID;
    if (m1.cnt == -1) {
        ID = m1.data[0];
        m1 = var[m1.data[0]];
    }
    vector tmp = m1;
    tmp.cnt=1;
    long long d = 0;
    for (int i = m1.cnt - 1; i >= 0; i--)
        d = m1.data[i] - d;
    tmp.data[0] = d;
    var[ID] = tmp;
    return tmp;
}

vector compADD(vector m1) {
    int ID;
    if (m1.cnt == -1) {
        ID = m1.data[0];
        m1 = var[m1.data[0]];
    }
    vector tmp = m1;
    tmp.cnt = 1;
    long long d = 0;
    for (int i = 0; i < m1.cnt; i++)
        d += m1.data[i];
    tmp.data[0] = d;
    var[ID] = tmp;
    return tmp;
}

vector MUL(vector m1, vector m2) {
    if (m1.cnt == -1)
        m1 = var[m1.data[0]];
    if (m2.cnt == -1)
        m2 = var[m2.data[0]];
    vector tmp;
    if (m1.cnt == 1) {
        tmp = m2;
        for (int i = 0; i < m2.cnt; i++)
            tmp.data[i] *= m1.data[0];
    } else if (m2.cnt == 1) {
        tmp = m1;
        for (int i = 0; i < m1.cnt; i++)
            tmp.data[i] *= m2.data[0];
    }
    return tmp;
}

vector SUB(vector m1, vector m2) {
    if (m1.cnt == -1)
        m1 = var[m1.data[0]];
    if (m2.cnt == -1)
        m2 = var[m2.data[0]];
    vector tmp;
    if (m1.cnt == 1) {
        tmp = m2;
        for (int i = 0; i < m2.cnt; i++)
            tmp.data[i] = m1.data[0] - tmp.data[i];
    } else if (m2.cnt == 1) {
        tmp = m1;
        for (int i = 0; i < m1.cnt; i++)
            tmp.data[i] -= m2.data[0];
    }
    return tmp;
}

vector ADD(vector m1, vector m2) {
    if (m1.cnt == -1)
        m1 = var[m1.data[0]];
    if (m2.cnt == -1)
        m2 = var[m2.data[0]];
    vector tmp;
    if (m1.cnt == 1) {
        tmp = m2;
        for (int i = 0; i < m2.cnt; i++)
            tmp.data[i] += m1.data[0];
    } else if (m2.cnt == 1) {
        tmp = m1;
        for (int i = 0; i < m1.cnt; i++)
            tmp.data[i] += m2.data[0];
    }
    return tmp;
}

int isNum(char *s) {
    for (int i = 0; s[i]; i++)
        if (s[i] < '0' || s[i] > '9')
            return 0;
    return 1;
}

int isAllNum(int l, int r) {
    for (int i = l; i <= r; i++)
        if (!isNum(item[i]))
            return 0;
    return 1;
}

long long strToNum(char *s) {
    long long d = 0;
    for (int i = 0; s[i]; i++)
        d = 10 * d + s[i] - '0';
    return d;
}

void deal(int *l, int *r) {
    while (1) {
        if (strcmp(item[*l], "(") || strcmp(item[*r], ")"))
            return;
        int t = 0;
        for (int i = *l; i <= *r; i++) {
            if (strcmp(item[i], "(") == 0)
                ++t;
            else if (strcmp(item[i], ")") == 0)
                --t;
            else if (t == 0)
                return;
        }
        ++(*l);
        --(*r);
    }
}

vector calc(int l, int r) {
    deal(&l, &r);
    vector tmp;
    if (isAllNum(l, r)) {
        tmp.cnt = 0;
        for (int i = l; i <= r; i++)
            tmp.data[tmp.cnt++] = strToNum(item[i]);
        return tmp;
    }
    if (l == r) {
        tmp.cnt = -1;
        long long d = 0;
        for (int i = 0; item[l][i]; i++)
            d = d * 26 + (item[l][i] - 'a' + 1);
        tmp.data[0] = d;
        return tmp;
    }
    int j = -1, t = 0;
    for (int i = l; i <= r; i++) {
        if (strcmp(item[i], ")") == 0)
            ++t;
        else if (strcmp(item[i], "("))
            --t;
        else if (t == 0 && i > l &&
                 (!strcmp(item[i], "+") || !strcmp(item[i], "-") || !strcmp(item[i], "*") || !strcmp(item[i], "="))) {
            j = i;
            break;
        }
    }
    vector opera1, opera2;
    if (strcmp(item[j], "=") == 0) {
        opera2 = calc(j + 1, r);
        if (opera2.cnt == -1)
            opera2 = var[opera2.data[0]];
        opera1 = calc(l, j - 1);
        var[opera1.data[0]] = opera2;
        return opera2;
    }
    if (strcmp(item[j], "+") == 0) {
        opera2 = calc(j + 1, r);
        if (opera2.cnt == -1)
            opera2 = var[opera2.data[0]];
        opera1 = calc(l, j - 1);
        if (opera1.cnt == -1)
            opera1 = var[opera1.data[0]];
        return ADD(opera1, opera2);
    }
    if (strcmp(item[j], "-") == 0) {
        opera2 = calc(j + 1, r);
        if (opera2.cnt == -1)
            opera2 = var[opera2.data[0]];
        opera1 = calc(l, j - 1);
        if (opera1.cnt == -1)
            opera1 = var[opera1.data[0]];
        return SUB(opera1, opera2);
    }
    if (strcmp(item[j], "*") == 0) {
        opera2 = calc(j + 1, r);
        if (opera2.cnt == -1)
            opera2 = var[opera2.data[0]];
        opera1 = calc(l, j - 1);
        if (opera1.cnt == -1)
            opera1 = var[opera1.data[0]];
        return MUL(opera1, opera2);
    }
    if (strcmp(item[l + 1], "/") == 0) {
        opera1 = calc(l + 2, r);
        if (strcmp(item[l], "+") == 0)
            return compADD(opera1);
        if (strcmp(item[l], "-") == 0)
            return compSUB(opera1);
        if (strcmp(item[l], "*") == 0)
            return compMUL(opera1);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        char line[201];
        gets(line);
        int n = -1, t = 0, flag = 0;
        for (int k = 0; line[k]; k++) {
            if (line[k] != ' ') {
                if (!flag) {
                    ++n;
                    t = 0;
                    flag = 1;
                }
                item[n][t++] = line[k];
            } else {
                if (flag)
                    item[n][t] = '\0';
                flag = 0;
            }
        }
        item[n][t] = '\0';
        vector ans = calc(0, n);
        if (ans.cnt == -1)
            ans = var[ans.data[0]];
        for (int j = 0; j < ans.cnt; j++)
            printf("%lld%c", ans.data[j], j == ans.cnt - 1 ? '\n' : ' ');
    }
    return 0;
}
