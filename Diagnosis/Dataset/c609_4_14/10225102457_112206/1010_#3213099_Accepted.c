#include<stdio.h>
#include<stdlib.h>
int main()
{
    int input,n,m,i,temp;
    const char *dic = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    scanf("%d%d",&input,&n);
    char output[32] = {0};
    
    if(input == 0){
        printf("0");
        return 0;
    }
    for(i = 0; input != 0; i++){
        temp = input - abs(input%n);
        if(temp%n == 0 || input == 1) {
        	output[i] = *(dic+abs(input%n));
        	input = temp/n;
		}
        else{
        	output[i] = *(dic - n - abs(input%n));
        	input = (input + n + abs(input%n))/n;
		}
    }

    for(i--; i >= 0; i--){
        printf("%c",output[i]);
    }
    printf("\n");
    
    return 0;
}