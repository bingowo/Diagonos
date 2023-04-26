#include <stdio.h>
#include <stdlib.h>
int main(){
    int T, count;
    long long n;
    int *s;
    s = malloc(sizeof(int)*100);
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%lld", &n);
        count = 0;
        while(n!=0){
            s[count++] = n%2333;
            n /= 2333;
        }
        for(int j=0; j<count; j++){
            printf("%d ", s[count-1-j]);
        }
        if(count==0) printf("%d", 0);
        printf("%c" ,'\n');
    }
    return 0;
}