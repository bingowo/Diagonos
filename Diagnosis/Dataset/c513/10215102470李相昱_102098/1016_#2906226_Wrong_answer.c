#include <stdio.h>

int main() {
    int N,R;
    scanf("%d%d",&N,&R);
    char std[20] = "0123456789ABCDEFGHIK";
    char a[20];
    if(N==0){
        printf("0");
    }
    else{
        int i=0;
        while(N){
            if(N>0){
                a[i++] = std[N%R];
                N = N/R;
            } else if(N<0){
                if(N%R){
                    a[i++] = std[N-(N/R+1)*R];
                    N = N/R+1;
                }
                else{
                    a[i++] = std[N%R];
                    N = N/R;
                }
            }
        }
        for(int j =0;j<i;j++){
            printf("%c",a[i-j-1]);
        }
    }
    return 0;
}
