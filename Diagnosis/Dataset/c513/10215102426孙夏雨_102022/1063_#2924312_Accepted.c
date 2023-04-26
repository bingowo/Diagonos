#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int chang=0,kuan=0;
    scanf("%lld %lld",&chang,&kuan);
    long long int sum=0,square=0;
    if((chang>kuan)&&(chang%kuan==0)) sum+=(chang/kuan)*4*kuan;
    else if((kuan>chang)&&(kuan%chang==0)) sum+=(kuan/chang)*4*chang;
    else{
    while((chang!=1||kuan!=1)&&(chang>0&&kuan>0)){
        if(chang==kuan) square=chang;
        square=chang>kuan ? kuan:chang;
        sum+=4*square;
        if(chang>kuan) chang-=kuan;
        else kuan-=chang;
    }
    sum+=4*kuan;}
    printf("%lld\n",sum);
    return 0;
}
