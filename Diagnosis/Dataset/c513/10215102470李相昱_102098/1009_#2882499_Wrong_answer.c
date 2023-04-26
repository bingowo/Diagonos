#include <stdio.h>
#include <string.h>
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
    while(n--){
        char s[120];
        scanf("%s",s);
        int len = strlen(s) * 8;
        int i = 0;
        int sum = 0;
        while (s[i++]){
            int c1 = s[i-1];
            for(int j = 0;j<8;j++){
                if(c1&(1<<j)){
                    sum ++;
                }
            }
        }
        int d  = gcd(len,sum);
        printf("%d/%d\n",sum/d,len/d);
    }
    return 0;
}
