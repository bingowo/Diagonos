#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    scanf("%s", s);
    int sum = 0;
    if(strchr(s,'.')){
        int i = 0;
        for(;s[i] != '.';i++){
            if(s[i] == '2'){
                sum = sum * 3 -1;
            }else if(s[i] == '1'){
                sum = sum *3 + 1;
            }else{
                sum *=3;
            }
        }
        i++;
        int sum1 = 0,n = 1;
        for(;i < strlen(s);i++){
            if(s[i] == '2'){
                sum1 = sum1 * 3 - 1;
            }else if(s[i] == '1'){
                sum1 = sum1 *3 + 1;
            }else{
                sum1 *=3;
            }
            n *=3;
        }
        if(sum1 < 0){
            if(sum < 0){
                sum1 *= -1;
                printf("%d %d %d",sum,sum1,n);
            }else if(sum == 0){
                printf("%d %d",sum1,n);
            }else{
                sum--;
                sum1 += n;
                printf("%d %d %d",sum,sum1,n);
            }
        }else{
            printf("%d %d %d",sum,sum1,n);
        }
    }else{
        for(int i = 0;i < strlen(s);i++){
            if(s[i] == '2'){
                sum = sum * 3 -1;
            }else if(s[i] == '1'){
                sum = sum *3 + 1;
            }else{
                sum *=3;
            }
        }
            printf("%d",sum);
    }
    return 0;
}
