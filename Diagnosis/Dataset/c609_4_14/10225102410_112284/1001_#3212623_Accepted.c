#include <stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    for(int i = 0;i < num;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        char c[10000];
        int n = 0;
        if(a < 0){
            printf("-");
            a = -1 *a;
        }
        while(a != 0){
            int i = a % b;
            a = a / b;
            if(i <= 9) c[n] = 48 + i;
            else c[n] = i + 'A' - 10;
            n++;
        }
        for(int j = 0;j < n;j++){
            printf("%c",c[n - j - 1]);
        }
        printf("\n");
    }
    return 0;
}
