#include <stdio.h>
#include <string.h>


int main(){
    int a = 0;
    int none = 0;
    scanf("%d",&a);
    for(int i = 2; i < 10001;i++){
        int beishu = i*a;
        char A[1000000];
       // sprintf(A,"%d",beishu);
       //printf("%s",A);
        printf("\n");
        int length = strlen(A);
        int good = 0;
        for(int j =0; j < length;j++){
            if(A[j] == '0'||A[j] == '1'){
                good = 0;
            }else{
                good = 1;
                break;
            }
        }
        if(good == 0){
            printf("%s",A);
            none =1;
            break;
        }

    }
    if(none == 0){
         printf("-1");
    }

}

