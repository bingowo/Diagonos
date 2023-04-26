#include<stdio.h>
#include<stdlib.h>
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
        if(count==0) printf("%c", '\n');
        else{
            for(int j=0; j<count; j++){
                printf("%d ", s[count-1-j]);
            }
        }
        printf("%c" ,'\n');
    }
    free(s);
    return 0;
}