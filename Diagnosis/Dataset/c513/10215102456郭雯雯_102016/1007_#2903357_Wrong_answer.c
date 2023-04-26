#include<stdio.h>
#include<string.h>

int main(){
    int t,m=0;
    scanf("%d",&t);
    while(m<t){
        long long int n;
        scanf("%lld",&n);
        char s[32];
        int j=1,max=0;
        for(int i=0;i<32;i++){
            int num=0;
            if(n&j==1){num++;j<<1;}
            if(n&j==0){
                if(num>max)max=num;
                num=0;
            }
        }
        printf("case #%d:\n%d\n",m,max);
        m++;
    }
}
