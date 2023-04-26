#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<math.h>
int main(){
    int k, t, i, flag = 0;char sign;
    int a[9];
    scanf("%d", &t);
    for(k = 0; k < t; k++){
        flag = 0; i = 0;
        printf("case #%d:\n", k);
        scanf("%d%d%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8]);
        for(i = 0; i < 9; i++){
            if(flag == 0 && i == 8)printf("%d", a[i]);
            if(a[i] == 0)continue;
            else flag++;
            if(flag > 1){
                sign = a[i] >= 0?'+':'-';
                if(abs(a[i]) == 1)printf("%c", sign);
                else printf("%c%d", sign, abs(a[i]));
                if(i < 7)printf("x^%d", 8-i);
                if(i == 7)printf("x");
                if(i == 8)printf("%d", abs(a[i]));
            }
            if(flag == 1){
                sign = a[i] >= 0?'+':'-';
                if(abs(a[i]) == 1){
                    if(sign == '-')printf("%c", sign);
                }
                else{
                    if(sign == '-')printf("%c", sign);
                    printf("%d", abs(a[i]));
                } 
                if(i<6)printf("x^%d", 8-i);
            }
            
        }
        printf("\n");
    }
    system("pause");
	return 0;
}