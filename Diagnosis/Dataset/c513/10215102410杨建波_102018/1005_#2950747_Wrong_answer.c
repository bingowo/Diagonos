#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int T;
    scanf("%d",&T);
    for(T;T > 0;T--){
        char Oct[52] = {'\0'},Dec[155] = {'\0'};
        scanf("%s",Oct);
        int dec = 0,d = 0;
        for(int i = strlen(Oct)-1;i > 1;i--){
            int num = Oct[i] - '0',j = 0,digit = 1;
            while(digit && j <= 3*(strlen(Oct)-2)){
                if(j < dec){
                    digit = num * 10 + Dec[j] - '0';
                }
                else    digit = num * 10;
                Dec[j] = digit / 8 + '0';
                num = digit % 8;
                j++;
            }
            dec = j;
            }
        for(int i =strlen(Dec)-1;i > 0;i--){
            if(Dec[i] == '0'){
                Dec[i] = '\0';
            }
            else break;
        }
        printf("case #%d:\n0.",d);
        d++;
        for(int n = 0;dec > n;n++){
            printf("%c",Dec[n]);
        }
        printf("\n");
    }
}