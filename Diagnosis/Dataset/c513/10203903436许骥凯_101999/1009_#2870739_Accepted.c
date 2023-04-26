#include<stdio.h>

int gcd(int a, int b){
    if (!(b % a)) return a;
    return gcd(b%a, a);
}

int cal(int chr){
    int cnt = 0, flag = 1;
    for (int i = 0; i != 8; i++){
        if (flag & chr) cnt++;
        flag <<= 1;
    }
    return cnt;
}

int count(char *chr, int lo, int hi){
    if (hi - lo == 0) return cal(chr[lo]);
    int mid = lo + (hi - lo)/2;
    return count(chr, lo, mid) + count(chr, mid+1, hi);
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i != n; i++){
        char temp[120], c; int index = 0; 
        while ((c = getchar()) != '\n') temp[index++] = c;
        
        int cnt = count(temp, 0, index-1);
        int div = gcd(cnt, 8 * index);
        
        if (div == 0) printf("0\n");
        else printf("%d/%d\n", cnt / div, 8 * index / div);
    }
    return 0;
}