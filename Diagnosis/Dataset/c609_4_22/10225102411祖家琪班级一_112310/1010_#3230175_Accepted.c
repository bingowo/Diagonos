#include <stdio.h>
#include <math.h>
int main()
{
    int N,R,cnt = 0;
    char res[33];
    char *table = "0123456789ABCDEFGHIJ";//|R|<21
    scanf("%d%d",&N,&R);
    if(0 == N){
        printf("0");
        return 0;
    }
    do{
        if(N%R<0){
            res[cnt++] = table[N%R - R];
            N = N/R + 1;
        }
        else{
            res[cnt++] = table[N%R];
            N /= R;
        }
    }while(N);
    for(int i = cnt - 1;i>-1;i--){
        printf("%c",res[i]);
    }
    return 0;
}
