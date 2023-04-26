#include <stdio.h>

int main(){
    int a=0,num,number=0,sum=0;
    char now;
    scanf("%d",&num);
    while(a<num){
        while((now=getchar())!=EOF){
            number+=8;
            while(now!=0){
                if(now&1) sum++;
                now=now>>1;
            }
        }
        printf("%d/%d\n",sum,number);
        a++;
    }
    return 0;
}