#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    char p[1000];
    scanf("%s",s);
    int i = 2;
    char t[] = "0123456789ABCDEF";
    for(;i< strlen(s);i++){
        int m = 0;
        for(int j = 0;j<16;j++){
            if(s[i] == t[j]){
                m = j;
                break;
            }
        }
        for(int q = 3;q>=0;q--){
            p[(i-2)*4+q] = m%2;
            m = m/2;
        }
    }
    long long int qr=0,qi=0;
    long long int a,b;
    int k = strlen(p);
    for(int z=0;z<k;z++)   //计算复数整数
    {
        int r=p[z]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
    }
    if(qi==0)     //输出，没有虚部
    {
        printf("%lld\n",qr);
    }
    else       //输出，有虚部
    {
        if(qr!=0)  //有实部
        {
            printf("%lld",qr);
            if(qi>0) printf("+");
        }
        if(qi==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else {printf("%lld",qi);printf("i\n");}
    }
    return 0;



}