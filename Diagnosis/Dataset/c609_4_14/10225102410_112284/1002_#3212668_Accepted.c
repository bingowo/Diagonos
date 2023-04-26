#include <stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    for(int i = 0;i < num;i++){
        int a;
        scanf("%d",&a);
        char c[10000];
        int n = 0;
        while( a != 0){
            int t = a % 2;
            a = a / 2;
            c[n] = t + '0';
            n++;
        }
        int max = 1;
        int tem = 1;
        for(int j = 0;j < n - 1;j++){
            if(c[j] != c[j +1]){
                tem++;
            }else{
                tem = 1;

            }
             max = max > tem ? max : tem;
        }
        printf("case #%d:\n",i);
        printf("%d\n",max);
    }
    return 0;
}

