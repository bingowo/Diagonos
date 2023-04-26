#include <stdio.h>
int gcd(int x,int y){
    int z = x%y;
    while (z){
        x = y;
        y = z;
        z = x%y;
    }
    return y;
}
int main() {
    int n;
    scanf("%d",&n);
    getchar();
    while(n--){
        char a;
        int sum = 0;
        int q = 0;
        while (scanf("%c",&a)&&(a!='\n')){
            q++;
            int c1 = a;
            for(int j = 0;j<8;j++){
                if(c1&(1<<j)){
                    sum ++;
                }
            }
        }
        int len = q*8;
        int d  = gcd(len,sum);
        printf("%d/%d\n",sum/d,len/d);
    }
    return 0;
}
