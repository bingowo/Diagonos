#include <stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    for(int i = 0;i < num;i++){
        int a;
        scanf("%d",&a);
        int ans[10000];

        int n = 0;

        while(a != 0){
            int tem = a % 2333;
            a = a / 2333;
            ans[n] = tem;
            n++;
        }
        for(int j = 0;j < n;j++){
            printf("%d ",ans[n - j - 1]);
        }
         printf("\n");
    }
    return 0;
}

