#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int qr, qi, a, b;
    char c;                 //处理输入

    //输入的几种情况：1，i，-i，2i，-2i，1+i，1-i，1+2i

    if(scanf("%lld",&qr)==0){
        //-i,+i
        qi = 0;
        scanf("%c",&c);
        if(c == '+') qr = 1;
        else qr = -1;
    }

    else if((c=getchar())== 'i'){
        //bi
        qi = qr;
        qr = 0;
    }

    else if(c == '\n' || c == EOF){
        //a
        qi = 0;
    }
    else{
        scanf("%lldi",&qi);
        if(c == '-') qi = -qi;
    }




    //qr+qi i =(a=bi)(-1+i)+r
    //a = (qi + r -  qr)/2
    //b = -(qr + qi - r)/2

    int ans[10000]={0};
    int num = 0;
    do{
        int r = 1;
        if(qr%2 == qi%2) r = 0;
        ans[num++] = r;

        a = (qi - qr + r)/2;
        b = -(qr + qi - r)/2;

        qr = a;
        qi = b;
    }while(a != 0 || b != 0);

    while(num > 0){
        printf("%d",ans[num - 1]);
        num--;
    }

    return 0;
}
