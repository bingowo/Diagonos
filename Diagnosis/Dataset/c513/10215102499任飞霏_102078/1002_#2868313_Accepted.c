#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        char str[100] = {};
        scanf("%s",str);
        int table[130];
        for(int j = 0;j < 130;j++)table[j] = -1;
        int len = 0;
        table[str[len]] = 1;
        while(str[len + 1] == str[len])len++;
        table[str[len + 1]] = 0;
        int p = 2;
        long long ans = 0;
        for(int j = len + 1;str[j];j++){
            len++;
            if(table[str[j]] == -1)table[str[j]] = p++;
        }
        long long mul = 1;
        for(int j = len;j >= 0;j--){
            ans += table[str[j]] * mul;
            mul *= p;
        }
        printf("case #%d:\n%lld\n",i,ans);
    }
    return 0;
}
