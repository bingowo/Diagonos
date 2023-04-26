#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int T;
    scanf("%d",&T);
    char L[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    while(T-->0){
        int N,R,i = 0,len = 0,flag = 1;
        char res[100];
        scanf("%d %d",&N,&R);
        if(N < 0) {flag = -1;N = -N;}
        do{
            res[i++] = L[N%R];
            N /= R;
            len++;
        }while(N > 0);
        if(flag == -1) printf("-");
        for(int j = len - 1;j>=0;j--){
            printf("%c",res[j]);
        }
        printf("\n");
    }
}



