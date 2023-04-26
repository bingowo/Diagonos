#include <stdio.h>
#include <stdlib.h>

long long int GCD(long long int m,long long int n)
{
    long int temp;
    if(m<n) temp=m,m=n,n=temp;     //m中放较大数
    if(m%n==0) return n;
    temp=n,n=m%n,m=temp;
    return(GCD(m,n));
}


int countOne(int a){
    int com=1;
    int res=0;
    for(int i=0;i<8;i++){
        if((a&com)!=0) res++;
        com=com<<1;
    }
    return res;
}

int main()
{
    int T;
    for(scanf("%d\n",&T);T>0;T--){

        char a[120];
        int j=0;

        //while((c=getch())=='\n');
        while((a[j] = getchar()) != '\n') j++;

        long long int digits=0,num=0;
        while(j>0){
            digits++;
            num=num+countOne(a[j]);
            j--;
        }

        digits=digits*8;
        long long int gcd=GCD(digits,num);
        digits=digits/gcd;
        num=num/gcd;

        printf("%lld/%lld\n",num,digits);
    }
    return 0;
}
