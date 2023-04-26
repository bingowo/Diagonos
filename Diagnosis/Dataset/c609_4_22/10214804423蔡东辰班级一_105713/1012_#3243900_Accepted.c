#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void divo(char c, char* dec);
int main(){
    int T, len;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
    	char dec[200] = {0};
    	char oct[60] = {0};
        scanf("%s", oct);
        len = strlen(oct);
        for(int j = len-1; j > 1; j--){
            divo(oct[j], dec);
        }
        printf("case #%d:\n0.%s\n", i, dec);
    }
}
void divo(char c, char* dec){
    int numrator = c - '0';//分子
    if(strlen(dec) == 0){
        int i = 0;
        while(numrator % 8){
            dec[i++] = '0' + numrator * 10 / 8;
            numrator = numrator * 10 % 8;
        }
    }
    else{
        int i = 0;
        while(1){
        	int temp_bit;
			temp_bit = (dec[i] >= '0' && dec[i]<='9')? dec[i]-'0' : 0;
			dec[i] = (numrator*10 + temp_bit)/8 + '0';
            numrator = (numrator*10 + temp_bit)%8;
            i++;
            if(numrator==0 && dec[i]=='\0'){
            	break;
			}
        }
    }
    return;
}