#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long long a=0,b=0;
    char hex[100];
    int cplx[1000],pow[2][4] = {{1,-1,0,2},{0,1,-2,2}};
    scanf("0x%s",hex);
    int l=strlen(hex),cnt2 = 0;
    long long wei = 1;
    for(int i=0;i<l;i++){
        int tmp = (hex[i] >= 'A')?(hex[i] - 'A' + 10):(hex[i] - '0');
        int cnt = 4;
        for(int j = 4*(i+1)-1;cnt>0;j--){
            cplx[j] = tmp%2;
            tmp /= 2;
            cnt--;
            cnt2++;
        }
    }//cplx数组中是正序存放的01串,长度为cnt2
    int cnt3 = 0;
    for(int i = cnt2-1;i>-1;i--){
        long long tmpa = cplx[i]*pow[0][(cnt2-i-1)%4]*wei;
        long long tmpb = cplx[i]*pow[1][(cnt2-i-1)%4]*wei;
        a += tmpa;
        b += tmpb;
        cnt3++;
        if(cnt3%4 == 0) wei *= -4;
    }
    if(a == 0 && b != 0){
        if(b != 1 && b != -1) printf("%lldi",b);
        else if(b==1) printf("i");
        else printf("-i");
    }
    else if(b == 0 && a != 0) printf("%lld",a);
    else if(a == 0 && b == 0) printf("0");
    else{
        if(b != 1 && b != -1){
            if(b > 0) printf("%lld+%lldi",a,b);
            else printf("%lld%lldi",a,b);
        }
        else if(b == 1) printf("%lld+i",a);
        else printf("%lld-i",a);
    }
    return 0;
}
