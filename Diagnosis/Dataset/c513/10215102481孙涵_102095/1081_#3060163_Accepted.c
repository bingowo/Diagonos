#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 95;


void multi(int * result,int a, int n);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int a,n;
        scanf("%d %d",&a,&n);
        int result[100] = {1};
        multi(result,a,n);
        printf("case #%d:\n",t);
        if(n == 0){
            printf("1\n");
        }else if(n == 1){
            printf("%d\n",a);
        }else{
            int m;
            for(m = 94; result[m] == 0; m--);
            for(int k = m; k >= 0; k--){
                printf("%d",result[k]);
            }
            printf("\n");
        }
    }
    return 0;
}

void multi(int * result,int a, int n){
    int i,carry;
    i = 0;
    carry = 0;
    for(i = 0; i < n; i++){//n次方
        for(int j = 0; j < 95; j++){
            int t = result[j]*a + carry;
            result[j] = t % 10;
            carry = t / 10;
        }
    }


}

