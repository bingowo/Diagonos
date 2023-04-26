#include <stdio.h>
#include <stdlib.h>
int main(){
    char A[1000];
    char B[1000];
    while(scanf("%s",A)){
        if(scanf("%s",B)==EOF)break;
        else{
            printf("%s",A);
        }
    }
    return 0;
}
