#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1e6 + 7
#define W 1002

int gcd(int a, int b){
    if (!(a % b)) return b;
    return gcd(b, a % b);
}

int main(){
    int groud[W];
    int n, s, p; scanf("%d%d%d", &n, &s, &p);
    groud[0] = W, groud[n+1] = W;
    for (int i = 1; i <= n; i++) scanf("%d", &groud[i]);
    
    int lres = s / 2, rres = s / 2, left, right, left_l ,right_l, lfz = 0, lfm = 0, rfz = 0, rfm = 0;
    while(s){
        left = p, right = p;
        while(groud[left] >= groud[left - 1]) left--;
        while(groud[right] >= groud[right + 1]) right++;

        left_l = left, right_l = right;
        while(groud[left_l] == groud[left_l+1]) left_l++;
        while(groud[right_l] == groud[right_l-1]) right_l--; 

        int left_need = left_l - left + 1, right_need = right - right_l + 1;
        int left_s = lres, right_s = rres;

        if (left_l >= p) right_s += left_s, left_s = 0;
        else if (right_l <= p) left_s += right_s, right_s = 0;

        if (left_l == right && right_l == left){
            if (left_need <= s) for (int i = left; i <= right; i++) groud[i]++, s--;
            else{
                lfm = left_need, lfz = left_s + right_s + s % 2; break;
            }
        }
        else{
            if (left_need > left_s && right_need > right_s){
                lfm = left_need * 2, lfz = left_s * 2 + s % 2, rfm = right_need * 2, rfz = right_s * 2 + s % 2;
                break; 
            }
            if (left_need <= left_s)
                for (int i = left; i <= left_l; i++) groud[i]++, left_s--, s--;
            if (right_need <= right_s)
                for (int i = right_l; i <= right; i++) groud[i]++, right_s--, s--;
            lres = left_s, rres = right_s;
        } 
    }

    for (int i = 1; i <= n; i++){
        printf("%d", groud[i]);
        if (lfz != 0 && i >= left && i <= left_l) printf("+%d/%d", lfz / gcd(lfm, lfz), lfm / gcd(lfm, lfz));
        else if (rfz != 0 && i >= right_l && i <= right) printf("+%d/%d", rfz / gcd(rfm, rfz), rfm / gcd(rfm, rfz));
        printf("%c", i == W - 2? '\n': ' '); 
    }
    return 0;
}