#include<stdio.h>
#include<math.h>

int main(){
    int a; scanf("%d", &a);
    while(a){
        double f = a * log10(a);
        f -= (int)f;
        printf("%d\n", (int)pow(10, f));
        scanf("%d", &a);
    }
    return 0;
}