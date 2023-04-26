#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long

typedef struct {
    ll data[80];
    int cnt;
}Vector;

Vector var[20000];
char item[80][10];

int id(char*);
int isNum(char*);
int allNum(int l, int r);
Vector add(Vector, Vector);
Vector sub(Vector, Vector);
Vector mult(Vector, Vector);
Vector compAdd(Vector);
Vector compSub(Vector);
Vector compMult(Vector);
void deal(int*, int*);
Vector calc(int, int);


int main()
{
    int N;
    scanf("%d",&N);
    for(int t=0; t<N; ++t) {
        int n = -1;
        do {
            scanf("%s",item[++n]);
        }while(getchar() != '\n');
        Vector ans = calc(0, n);
        if(ans.cnt == -1) ans = var[ans.data[0]];
        for(int i=0; i<ans.cnt; ++i)
            printf("%lld%c",ans.data[i], i<ans.cnt-1?' ':'\n');
    }
    return 0;
}


Vector calc(int l, int r) {
    deal(&l, &r);
    Vector temp = {{0}, 0};

    if(allNum(l, r)) {
        while(l <= r) 
            temp.data[temp.cnt++] = atoll(item[l++]);
        return temp;
    }
    if(l == r) {
        temp.cnt = -1;
        temp.data[0] = id(item[l]);
        return temp;
    }
    int i=l, flag=0;
    for(int k=l; k<=r; ++k) {
        if(!strcmp(item[k],"(")) ++flag;
        else if(!strcmp(item[k],")")) --flag;
        else if(!flag && k>l && (!strcmp(item[k],"+")||!strcmp(item[k],"-")||!strcmp(item[k],"*")||!strcmp(item[k],"="))) {
            i = k;  break;
        }
    }
    Vector op1, op2;
    if(!strcmp(item[l+1], "/")) {
        op1 = calc(l+2, r);
        if(!strcmp(item[l], "+")) return compAdd(op1);
        if(!strcmp(item[l], "-")) return compSub(op1);
        if(!strcmp(item[l], "*")) return compMult(op1);
    }
    op2 = calc(i+1, r);
    op1 = calc(l, i-1);
    if(!strcmp(item[i], "=")) {
        if(op2.cnt == -1) op2 = var[op2.data[0]];
        var[op1.data[0]] = op2;
        return op2;
    }
    if(!strcmp(item[i], "+")) return add(op1, op2);
    if(!strcmp(item[i], "-")) return sub(op1, op2);
    if(!strcmp(item[i], "*")) return mult(op1, op2);
}

void deal(int* l, int* r) {
    while(1) {
        if(strcmp(item[*l],"(") || strcmp(item[*r],")")) return;
        int cnt = 0;
        for(int i=*l; i<=*r; ++i) {
            if(!strcmp(item[i],"(")) ++cnt;
            else if(!strcmp(item[i],")")) --cnt;
            else if(cnt == 0) return;
        }
        ++(*l); --(*r);
    }
}

int id(char* s) {
    int ans = 0;
    for(int i=0; s[i]; ++i)
        ans = ans * 26 + s[i] - 'a';
    return ans;
}

int isNum(char* s) {
    int i = 0;
    if((s[i]=='+' || s[i]=='-') && s[i+1]) ++i;
    for(; s[i]; ++i)
        if(!isdigit(s[i])) return 0;
    return 1;
}

int allNum(int l, int r) {
    for(int i=l; i<=r; ++i)
        if(!isNum(item[i])) return 0;
    return 1;
}

Vector add(Vector a, Vector b) {
    if(a.cnt == -1) a = var[a.data[0]];
    if(b.cnt == -1) b = var[b.data[0]];
    Vector ans;
    if(a.cnt == 1) {
        ans = b;
        for(int i=0; i<b.cnt; ++i)
            ans.data[i] += a.data[0];
    }else if(b.cnt == 1) {
        ans = a;
        for(int i=0; i<a.cnt; ++i)
            ans.data[i] += b.data[0];
    }
    return ans;
}

Vector sub(Vector a, Vector b) {
    if(a.cnt == -1) a = var[a.data[0]];
    if(b.cnt == -1) b = var[b.data[0]];
    Vector ans;
    if(a.cnt == 1) {
        ans.cnt = b.cnt;
        for(int i=0; i<b.cnt; ++i)
            ans.data[i] = a.data[0] - b.data[i];
    }else if(b.cnt == 1) {
        ans = a;
        for(int i=0; i<a.cnt; ++i)
            ans.data[i] -= b.data[0];
    }
    return ans;
}

Vector mult(Vector a, Vector b) {
    if(a.cnt == -1) a = var[a.data[0]];
    if(b.cnt == -1) b = var[b.data[0]];
    Vector ans;
    if(a.cnt == 1) {
        ans = b;
        for(int i=0; i<b.cnt; ++i)
            ans.data[i] *= a.data[0];
    }else if(b.cnt == 1) {
        ans = a;
        for(int i=0; i<a.cnt; ++i)
            ans.data[i] *= b.data[0];
    }
    return ans;
}

Vector compAdd(Vector a) {
    int index = -1;
    if(a.cnt == -1) {
        index = a.data[0];
        a = var[index];
    }
    Vector ans = {{0}, 1};
    for(int i=0; i<a.cnt; ++i) 
        ans.data[0] += a.data[i];
    if(index != -1) var[index] = ans;
    return ans;
}

Vector compSub(Vector a) {
    int index;
    if(a.cnt == -1) {
        index = a.data[0];
        a = var[index];
    }
    Vector ans = {{0}, 1};
    for(int i=a.cnt-1; i>=0; --i) 
        ans.data[0] = a.data[i] - ans.data[0];
    var[index] = ans;
    return ans;
}

Vector compMult(Vector a) {
    int index;
    if(a.cnt == -1) {
        index = a.data[0];
        a = var[index];
    }
    Vector ans = {{1}, 1};
    for(int i=0; i<a.cnt; ++i) 
        ans.data[0] *= a.data[i];
    var[index] = ans;
    return ans;
}






