#include<stdio.h>

int gcd(int a, int b){
    if (!(b % a)) return a;
    return gcd(b%a, a);
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i != n; i++){
        char temp[120], c; int index = 0; 
        while ((c = getchar()) != '\n') temp[index++] = c;
        int cnt = 0;
        for (int j = 0; j != index; j++){
            int t = temp[j], flag = 1;
            for (int k = 0; k != 8; k++){
                if (flag & t) cnt++;
                flag <<= 1;
            }
        }
        int sub = gcd(cnt, 8 * index);
        if (sub == 0) printf("0\n");
        else 
            printf("%d/%d\n", cnt / sub, 8 * index / sub);
    }
    return 0;
}