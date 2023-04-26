#include <stdio.h>
#include <stdlib.h>

int solve(long long a)
{
    int fir = a%2,sec;
    int count = 1;
    int temp=1;
    while(a){
        a>>=1;
        sec = a%2;
        if(sec != fir){
            temp++;
        }
        else{
            if(temp>count){
                count = temp;
            }
        }
        fir = sec;
    }
    if(temo>count){
        count = --temp;
    }
    return count;
}
int main()
{
    int total;
    scanf("%d",&total);
    for(int i=0;i<total;i++){
        long long a;
        scanf("%lld",&a);
        printf("case #%d:\n",i);
        solve(a);
        printf("\n");
    }
    return 0;
}
