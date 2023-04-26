#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char Base64[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789*/";
int main(){
    int T, *num, count, temp, sum, len;
    scanf("%d", &T);
    char s[101];
    for(int k=0; k<T; k++){
        scanf("%s", s);
        len = strlen(s);
        printf("case #%d:\n", k);
        for(int i=0; i<len/3; i++){
            num = (int*)calloc(24,sizeof(int));
            for(int j=0; j<3; j++){
                temp = (int)s[i*3+j];
                count = 1;
                while(temp!=0){
                    if(temp%2==1) num[(j+1)*8-count] = 1;
                    count++;
                    temp /= 2;
                }
            }
            for(int j=0; j<4; j++){
                sum = 0;
                for(int t=0; t<6; t++){
                    sum = sum*2+num[j*6+t];
                }
                printf("%c", Base64[sum]);
            }
            free(num);
        }
        num = (int*)calloc(24,sizeof(int));
        if(len%3!=0){
            for(int i=0; i<len%3; i++){
                temp = (int)s[len/3*3+i];
                count = 1;
                while(temp!=0){
                    if(temp%2==1) num[(i+1)*8-count] = 1;
                    count++;
                    temp /= 2;
                }
            }
            for(int i=0; i<len%3+1; i++){
                sum = 0;
                for(int j=0; j<6; j++){
                    sum = sum*2+num[i*6+j];
                }
                printf("%c", Base64[sum]);
            }
            for(int i=0; i<3-len%3; i++) printf("%c", '=');
        }
        printf("%c", '\n');
        free(num);
    }
    return 0;
}