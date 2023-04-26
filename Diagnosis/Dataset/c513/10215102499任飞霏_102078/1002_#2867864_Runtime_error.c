#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int table[150],i,n;

    scanf("%d",&n);
    char number[100];
    for(i = 0;i <= 150;i++){
        number[i] = 0;
    }
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
                //数进制数
                count++;
            printf("count=%d",count);
        }
        }
        for(int k = strlen(number) - 1;k >= 0;k--){
            if(k == 0)table[number[k]] = 1;
            else if(k == 1)table[number[k]] = 0;
            else if(table[number[k]] == -1)table[number[k]] = k;
            result = result * count + table[number[k]];
        }

        printf("case #%d:\n",m);
        printf("%lld\n",result);

    }
    return 0;
}
