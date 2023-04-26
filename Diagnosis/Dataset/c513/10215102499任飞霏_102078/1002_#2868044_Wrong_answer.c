#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int table[150],i,n;
    scanf("%d",&n);
    char number[100];
    for(int m = 0;m < n;m++){
        //初始化
        for(i = 0;i <= 150;i++){
            table[i] = 0;
        }
        long long int result = 0;
        scanf("%s",number);
        int count = 0;
        for(int j = 0;j < strlen(number);j++){
            if(table[number[j]] != -1){
                table[number[j]] = -1;
                //进制数
                count++;
            //printf("count=%d",count);
            }
        }
        table[number[0]] = 1;
        int k;
        for( k = 1;k < strlen(number) - 1;k++){
            if(table[number[k]] == table[number[k - 1]])table[number[k]] = 1;
        }
        table[number[k + 1]] = 1;
        int num = 2;
        for(int q = k+2;q < strlen(number) - 1;q++){
            if(table[number[q]] == -1)table[number[q]] = num;
            num++;
        }
        for(int p = strlen(number) - 1;p > 0;p--){
            result = result * count + table[number[p]];
        }
        printf("case #%d:\n",m);
        printf("%lld\n",result);

    }
    return 0;
}
