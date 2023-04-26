//1078
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int T, num, isFirst;
    scanf("%d", &T);
    for(int t = 0; t < T; t ++){
        printf("case #%d:\n", t);
        isFirst = 1;
        for(int i = 0; i < 7; i ++){
            scanf("%d", &num);
            if(abs(num) > 1){ //系数绝对值大于1时
                if(isFirst){
                    printf("%dx^%d", num, 8-i);
                    isFirst = 0;
                }else printf("%+dx^%d", num, 8-i);
            }else if(abs(num) == 1){ //系数为1或-1时
                if(isFirst){
                    if(num == 1) printf("x^%d", 8-i);
                    else printf("-x^%d", 8-i);
                    isFirst = 0;
                }else{
                    if(num == 1) printf("+x^%d", 8-i);
                    else printf("-x^%d", 8-i);
                }
            }
        }
        scanf("%d", &num); //x^1;
        if(abs(num) > 1){ //系数绝对值大于1时
            if(isFirst){
                printf("%dx", num);
                isFirst = 0;
            }else printf("%+dx", num);
        }else if(abs(num) == 1){ //系数为1或-1时
            if(isFirst){
                if(num == 1) printf("x");
                else printf("-x");
                isFirst = 0;
            }else{
                if(num == 1) printf("+x");
                else printf("-x");
            }
        }
        scanf("%d", &num); //x^0;
        if(abs(num) > 0){
            if(isFirst) printf("%d", num);
            else printf("%+d", num);
        }else{
            if(isFirst) printf("0");
        }
        printf("\n");
    }
    return 0;
}