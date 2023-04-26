#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        char p[100];
        int sum = 0;
         scanf("%s",p);
        for(int j = strlen(p) - 1;j > -1 ;j--){
            if(*(j+p) == '-'){
                sum = sum*3 - 1;
            }
            else if(*(j+p) == '0')
                sum = sum * 3;
            else
                sum  = sum * 3 +1; 
        }
        printf("case #%d:\n%d\n",i,sum);
    }
}