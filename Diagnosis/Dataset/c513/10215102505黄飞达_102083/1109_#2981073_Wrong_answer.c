#include<stdio.h>
#include<string.h>

int main(){
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++){
        printf("case #%d:\n", t);
        int first=1;//irst第一个非0系数
        for (int i=8; i>=2; i--){
            int num=0;
            scanf("%d", &num);
            if (num==0) continue;
            else {
                if (first){
                    if (num==1) printf("x^%d", i);
                    else if (num==-1) printf("-x^%d", i);
                    else printf("%dx^%d", num, i);
                    first=0;
                }
                else {
                    if (num==1) printf("+x^%d", i);
                    else if (num==-1) printf("-x^%d", i);
                    else {
                        if (num>0) printf("+");
                        printf("%dx^%d", num, i);
                    }
                }
            }
        } 
        //特殊处理x^1
        int num=0;
        scanf("%d", &num);
        if (num!=0){
            if (num>0) printf("+");
            if (num==1) printf("x");
            else if (num==-1) printf("-x");
            else printf("%dx", num);

        }
        //特殊处理常数项
        scanf("%d", &num);
        if (first) printf("%d\n", num);
        else {
            if (num>0) printf("+%d\n", num);
            else if (num<0) printf("%d\n", num);
        }
    }
    return 0;
}