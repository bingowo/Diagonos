#include <stdio.h> //没什么好备注的了
#include <string.h>
int main(){
    int T, a, n, count, temp;
    int num[100001];
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        scanf("%d %d", &a, &n);
        printf("case #%d:\n", t);
        memset(num, 0, sizeof(num));
        count = 0;
        if(n==0) printf("1\n");
        else{
            num[count++] = a;
            for(int i=1; i<n; i++){
                temp = 0;
                for(int j=0; j<count; j++){
                    num[j] = num[j]*a+temp;
                    temp = num[j]/10;
                    num[j] %= 10;     
                }
                if(temp!=0) num[count++] = temp;
            }
            for(int i=0; i<count; i++) printf("%d", num[count-i-1]);
            printf("\n");
        }
    }
    return 0;
}