#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int table[150],i,n,copy;

    for(i = 0;i <= 150;i++){
        table[i] = -1;
    }
    scanf("%d",&n);
    copy = n - 1;
    while(n--){
        long long int result = 0;
        char number[100];
        scanf("%s",number);
        int count = 0;
        for(int j = 0;j <= strlen(number);j++){
            if(table[number[j]] == -1){
                count++;
        }
            table[number[j]]++;
        }
        for(int k = strlen(number) - 1;k >= 0; k--){
            result = result * count + table[number[k]] + 1;
        }
        printf("case #%d:\n",copy - n);
        printf("%lld\n",result);

    }
    return 0;
}
