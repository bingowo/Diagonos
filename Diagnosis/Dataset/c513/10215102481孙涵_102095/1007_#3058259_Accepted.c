#include <stdio.h>
#include <stdlib.h>

void func(int num);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int num;
        scanf("%d",&num);
        printf("case #%d:\n",t);
        func(num);
    }
}

void func(int num){
    //a/b = c ......d
    int a = num;
    int c;//商
    int d;//余数;
    int pl = 0;
    char s[50];
    for(int i = 0; i < 50; i++){
        s[i] = -1;
    }
    while(a > 0){
        d = a % 2;
        c = a / 2;
        a = c;
        s[pl] = d;
        pl++;
    }
    //找到了二进制串
   int length = 1;
    int max = 1;
    int pl_start = 0;
    int pl_end;
    for(; pl_start < pl -1; pl_start++){
        length = 1;
        pl_end = pl_start;
        while(s[pl_end] != s[pl_end+1] && pl_end < pl-1){
            length++;
            pl_end++;
        }
        if(length > max){
            max = length;
        }
    }
    printf("%d\n",max);
}
