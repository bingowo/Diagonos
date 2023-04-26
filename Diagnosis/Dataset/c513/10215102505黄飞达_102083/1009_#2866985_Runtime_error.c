#include<stdio.h>

int gcd(int m,int n)
{
    if (m<n) {m^=n; n^=m; m^=n;}
    if (m%n==0) return n;
    else return gcd(n,m%n);
}

int func(char c){
    int temp = c, count = 0;
    for (int i = 0; i < 8; i++){
        count += (1 & temp);
        temp >>= 1;
    }
    return count;
}

int main(){
    int n;
    
    scanf("%d ", &n);
    for(int i = 0; i < n; i++){
        int count1 = 0, len = 0;
        char s[100];
        for (int j = 0; j < sizeof(s); j++){
            s[j] = '\0';
        }
        gets(s);
        for (int j = 0; j < sizeof(s); j++){
            if (s[j] == '\0'){
                len = j;
                break;
            }
            count1 += func(s[j]);
        }
        int sum = 8*len;
        int temp = gcd(sum, count1);
        if (temp != 1){
            count1 /= temp;
            sum /= temp;
        }
        printf("%d/%d\n", count1, sum);
    }
    return 0;
}