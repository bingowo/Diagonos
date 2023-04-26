#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1009];
    int t[1009];
    scanf("%s",s);
    int k=0;
    for(int i=2;i<strlen(s);i++){
        int d;
        if(s[i]>='A')d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned int flag=0x8;
        while(flag){
            if(d&flag)t[k++]=1;
            else t[k++]=0;
            flag=flag>>1;
        }
    }
    long long qr=0,qi=0;
    long long a,b;
    for(int i=0;i<k;i++){
        int r=t[i];
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;
        qi=b;
    }
    if(qi==0)printf("%lld\n",qr);
    else{
        if(qr!=0){
            printf("%lld",qr);
            if(qi>0)printf("+");
        }
        if(qi==1)printf("i\n");
        else if(qi==-1)printf("-i\n");
        else{
            printf("%lldi\n",qi);
        }

    }
    return 0;
}
