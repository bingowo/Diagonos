#include<stdio.h>

#define N 10000

typedef struct{
    int cnt, v[N];
}BIG;

BIG ItoB(int a){
    BIG temp = {0, {0}};
    do{
        temp.v[temp.cnt++] = a % 10;
        a /= 10;
    }while(a);
    return temp;
}

BIG mul(BIG a, BIG b){
    BIG temp = {a.cnt + b.cnt, {0}};
    for (int i = 0; i != b.cnt; i++){
        int carry = 0;
        for (int j = 0; j != a.cnt; j++){
            int t = a.v[j] * b.v[i] + carry + temp.v[i+j];
            temp.v[i+j] = t % 10;
            carry = t / 10; 
        }

        int k = i + a.cnt;
        while(carry){
            int t = carry + temp.v[k];
            temp.v[k++] = t % 10;
            carry = t / 10;
        } 
    }
    if (temp.v[temp.cnt - 1] == 0) temp.cnt--;
    return temp;
}

BIG Pow(BIG A, int fac){
    if (fac == 0) return ItoB(1);
    if (fac == 1) return A;
    BIG r = Pow(A, fac / 2);
    r = mul(r, r);
    if (fac % 2) r = mul(r, A);
    return r;
}

void output(BIG res, int mas){
    for (int i = mas - 1; i >= 0; i--)
        printf("%d", res.v[i]);
    printf("\n");
}

int main(){
    int pro; scanf("%d", & pro);
    for (int i = 0; i != pro; i++){
        printf("case #%d:\n", i);
        int a, fac, mas; scanf("%d%d%d", &a, &fac, &mas);
        BIG A = ItoB(a);
        BIG AA = Pow(A, fac);
        output(AA, mas);
    }
}