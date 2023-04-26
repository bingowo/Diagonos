#include <stdio.h>
#include <string.h>


int main(){
    int a = 0;
    scanf("%d",&a);
    for(int i = 0; i < 1001;i++){
        int beishu = i*a;
        char A[10000000];
        sprintf(A,"%d",beishu);
        int length = strlen(A);
        int good = 0;
        for(int j =0; j < length;j++){
            if(A[j] != '0'||A[j] != '1'){
                    good = 1;
                break;
            }else{
                ;
            }
        }
        if(good == 0){
            printf("%s",A);
            break;
        }

    }
    printf("-1");
}
