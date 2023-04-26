#include <stdio.h>

int main(){
    int num,a=0,b,number=1,first,second,now,new=0;
    scanf("%d",&num);
    while(a<num){
        scanf("%d",&b);
        first=b%2;
        b/=2;
        while(b!=0){
            second=b%2;
            b/=2;
            if(first!=second) {number++;}
            if(first==second) {break;}
            first=second;
        }
        first=second;
        now=number;
        new=1;
        if(b!=1){b=b*2;}
        if(b==1&&first!=1){
            now=now+1;}
        while(b!=0&&b!=2&&b!=1){
            second=b%2;
            b/=2;
            if(first!=second) {new++;}
            if(first==second) {
                if(new>now){
                    now=new;
                    b=b*2;
                    new=0;
                }
                if(new<=now){
                    b=b*2;
                    new=0;
                }
            }
            first=second;
        }

        printf("case #");
        printf("%d:\n",a);
        printf("%d\n",now);
        number=1;
        a++;
    }
    return 0;}