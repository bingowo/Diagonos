#include <stdio.h>
#include <math.h>
int main()
{
    int N,R,cnt = 0;
    char res[33];
    char *table = "0123456789ABCDEFGHIJ";//|R|<21
    scanf("%d%d",&N,&R);
    ///*
    do{
        res[cnt++] = table[abs(N%R)];
        N /= R;
    }while(N);
    for(int i = cnt - 1;i>-1;i--){
        printf("%c",res[i]);
    }
    //*/
    //printf("%d",N%R);
    return 0;
}