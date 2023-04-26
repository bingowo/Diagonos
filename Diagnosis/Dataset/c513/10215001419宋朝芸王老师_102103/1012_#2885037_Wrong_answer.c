#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int qr, qi, a, b;
    char c[2];                 //处理输入

    //输入的几种情况：1，i，-i，2i，-2i，1+i，1-i，1+2i

    if(scanf("%lld",&qr)==0){
            //-i,+i

    }

    if((c[0]=getchar())== 'i'){
        qi = qr;
        qr = 0;
    }
    else if(c[0] == '\n' || c == EOF){
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
