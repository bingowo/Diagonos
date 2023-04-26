#include<stdio.h>
#include<stdlib.h>

int cmp(const void *p1, const void *p2){
    return *(int*)p1 - *(int*)p2;
}

int cal(int a, int b){
    if (!(b % a)) return a;
    return cal(b % a, a);
}

void gcd(int *mod){
    int a = mod[0], b = mod[1];
    int m = cal(a, b);
    mod[0] /= m;
    mod[1] /= m;
}
int main(){
    int n, h; scanf("%d%d", &n, &h);
    int groud[1001] = {0}; int t = 0;
    for (int i = 0; i != n; i++) scanf("%d", &groud[t++]);
    qsort(groud, n, sizeof(int), cmp);
    int res = groud[0]; int mod[2] = {0};
    while(h){
        int i = 1, temp = 1;
        for (; i != n; i++)
            if (groud[i] == groud[i-1]) temp++;
            else break;
        if (i != n){
            int scale = groud[i] - groud[i-1];
            for (int j = 0; j != i; j++)
                groud[j] += scale;
            if(h >= scale * temp){
                h -= scale * temp;
                res = groud[i-1];
            }
            else{
                res += h / temp;
                mod[0] =  h % temp;
                mod[1] = temp;
                break;
            } 
        } 
        else{
            res += h / n;
            mod[0] = h % n;
            mod[1] = n;
            h = 0;
        }
    }

    if (mod[0]){
        gcd(mod);
        printf("%d+%d/%d\n", res, mod[0], mod[1]);
    }
    else if (res == 0){
        gcd(mod);
        printf("%d/%d", mod[0], mod[1]);
    }
    else printf("%d\n", res);
    return 0;
}