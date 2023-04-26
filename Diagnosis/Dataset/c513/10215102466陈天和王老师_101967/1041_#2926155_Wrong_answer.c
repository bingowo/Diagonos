

#include <stdio.h>
int main(){
    char s[51];
    char *p,*q;
    scanf("%s",s);
    p=s;
    q=s+1;

    int max=0;
    while(*q){
        //这个循环条件很重要，看后面指针是否为零
        int cnt=1;
        while(*p!=*q && *q){
            cnt++;
            p++;
            q++;
        }

        if(cnt>=max){
            max=cnt;
        }
        p++;
        q++;
    }
    printf("%d",max);
    return 0;
}