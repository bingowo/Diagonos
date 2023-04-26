//
// Created by Shizumu on 2022/4/4.
//
#include <stdio.h>
#include <string.h>

#define LEN 1000
typedef struct{
    int num[LEN];
    int sgn;
    int point;
}Fraction;
Fraction fadd(Fraction a, Fraction b);
Fraction fsub(Fraction a, Fraction b);

Fraction stofrac(char s[])
{
    char *p = NULL, *pend = NULL;
    Fraction fn;
    memset(&fn, 0, sizeof(fn));
    int idx = LEN - 1;
    fn.sgn = 1, fn.point = 0;
    for(p = s; *p; p ++);
    pend = p;
    while(1){
        p --;
        if(*p != '.' && *p != '-'){
            fn.num[idx --] = *p - '0';
        }else if(*p == '.'){
            fn.point =  pend - p - 1;
        }
        if(p == s || *p == '-'){
            if(*p == '-'){fn.sgn = -1;}
            break;
        }
    }

    return fn;
}

void PrintFrac(Fraction fn)
{
    if(fn.sgn == -1){printf("-");}
    int idx;
    for(idx = 0 ; fn.num[idx] == 0 && idx < LEN - fn.point; idx ++);
    if(idx == LEN){
        printf("0");
    }else{
        for(int cnt = 0; idx < LEN; idx ++, cnt ++){
            if(LEN - idx == fn.point){
                printf("%s.", cnt == 0 ? "0" : "");
            }
            printf("%d", fn.num[idx]);
        }
    }
}

int Fraccmp(Fraction a, Fraction b)
{
    int ret = 0, isSwap = 0;
    if(a.sgn == 1 && b.sgn ==- 1){
        ret = 1;
    }else if(a.sgn == -1 && b.sgn == 1){
        ret = -1;
    }else{
        if(a.point < b.point){
            Fraction temp; temp = a; a = b; b = temp;
            isSwap = 1;
        }
        //对齐
        int offset = a.point - b.point, idx;
        for(idx = 0 ; b.num[idx] == 0 && idx < LEN ; idx ++);
        memmove(b.num + idx - offset , b.num + idx, sizeof(int) * (LEN - idx));
        memset(b.num + (LEN - offset), 0, sizeof(int) * offset);
        if(isSwap){
            Fraction temp; temp = a; a = b; b = temp;
            isSwap = 0;
        }
        for( idx = 0; idx < LEN; idx ++){
            if(a.num[idx] > b.num[idx]){
                ret = 1;
                break;
            }else if(a.num[idx] < b.num[idx]){
                ret = -1;
                break;
            }
        }
        ret = ret * a.sgn;
    }

    return ret;
}

Fraction fadd(Fraction a, Fraction b)
{
    Fraction ret;
    int isSwap = 0;
    memset(&ret, 0, sizeof(ret));
    if(a.sgn * b.sgn == 1){
        if(a.point < b.point){
            Fraction temp; temp = a; a = b; b = temp;
            isSwap = 1;
        }
        int offset = a.point - b.point, idx;
        for(idx = 0 ; b.num[idx] == 0 && idx < LEN ; idx ++);
        memmove(b.num + idx - offset , b.num + idx, sizeof(int) * (LEN - idx));
        memset(b.num + (LEN - offset), 0, sizeof(int) * offset);
        ret.sgn = a.sgn, ret.point = a.point;
        if(isSwap){
            Fraction temp; temp = a; a = b; b = temp;
            isSwap = 0;
        }
        for(int i = LEN - 1; i > 0; i --){
            ret.num[i] = ret.num[i] + a.num[i] + b.num[i];
            if(ret.num[i] >= 10){
                ret.num[i] %= 10;
                ret.num[i - 1] += 1;
            }
        }
    }else{
        if(a.sgn == 1){
            b.sgn = 1;
            ret = fsub(a, b);
        }else if(b.sgn == 1){
            a.sgn = 1;
            ret = fsub(b, a);
        }
    }

    return ret;
}

Fraction fsub(Fraction a, Fraction b)
{
    Fraction ret;
    memset(&ret, 0, sizeof(ret));
    int c, isSwap = 0;
    if(a.sgn * b.sgn == 1){
        if((c = Fraccmp(a, b) * a.sgn) == 1){
            if(a.point < b.point){
                Fraction temp; temp = a; a = b; b = temp;
                isSwap = 1;
            }
            int offset = a.point - b.point, idx;
            for(idx = 0 ; b.num[idx] == 0 && idx < LEN ; idx ++);
            memmove(b.num + idx - offset , b.num + idx, sizeof(int) * (LEN - idx));
            memset(b.num + (LEN - offset), 0, sizeof(int) * offset);
            ret.sgn = a.sgn * isSwap, ret.point = a.point;
            if(isSwap){
                Fraction temp; temp = a; a = b; b = temp;
                isSwap = 0;
            }
            for(int i = LEN - 1; i > 0; i --){
                ret.num[i] = ret.num[i] + a.num[i] - b.num[i];
                if(ret.num[i] < 0){
                    ret.num[i] += 10;
                    ret.num[i - 1] -= 1;
                }
            }
        }else if(c == -1){
            ret = fsub(b, a);
            ret.sgn = a.sgn *  -1;
        }else{
            ret.sgn = 1;
        }
    }else{
        if(a.sgn == 1){
            b.sgn = 1;
            ret = fadd(a, b);
            ret.sgn = 1;
        }else if(b.sgn == 1){
            a.sgn = 1;
            ret = fadd(b, a);
            ret.sgn = -1;
        }
    }

    return ret;
}

Fraction fround(Fraction fn, int n)
{
    Fraction ret;
    memset(&ret, 0, sizeof (ret));
    ret.sgn = fn.sgn, ret.point = n;
    int idx;
    for(idx = 0; fn.num[idx] == 0 && idx < LEN - fn.point; idx ++);
    if(fn.point <= n){
        memmove(ret.num + idx - (n - fn.point), fn.num + idx, sizeof(int) * (LEN - idx));
    }else{
        memmove(ret.num + idx + (fn.point - n), fn.num + idx, sizeof(int) * (LEN - idx - (fn.point - n)));
        if(fn.num[LEN - (fn.point - n)] >= 5){
            ret.num[LEN - 1] += 1;
            for(int k = LEN - 1; ret.num[k] >= 10; k --){
                ret.num[k] %= 10;
                ret.num[k - 1] += 1;
            }
        }
    }
    return ret;
}

int main(void)
{
    char s1[LEN], s2[LEN];
    Fraction a, b;
    int n;
    scanf("%s %s %d", s1, s2, &n);
    a = stofrac(s1), b = stofrac(s2);
    PrintFrac(fround(fsub(a, b), n));

    return 0;
}
