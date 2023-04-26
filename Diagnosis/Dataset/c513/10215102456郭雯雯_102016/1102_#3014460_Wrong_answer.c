#include<stdio.h>
#include<math.h>

int num(long long a){
    double m=(double)a/4;
    int b=(int)sqrt(m);
    if(b*b*4<a)b++;
    return b;
}

int main(){
    long long n;
    scanf("%lld",&n);
    int m=num(n),x,y;
    if(n==0){x=0;y=0;}
    else{
        long long a,b,c,d,e;
        a=(long long)(2*m-2)*(2*m-2);
        b=(long long)(2*m-2)*(2*m-1);
        c=(long long)(2*m-1)*(2*m-1);
        d=(long long)2*m*(2*m-1);
        e=(long long)2*m*2*m;
        if(n>a&&n<=b){y=1-m;x=(n-a)-m+1;}
        else if(n>b&&n<=c){x=m-1;y=(n-b)-(m-1);}
        else if(n>c&&n<=d){y=m;x=(m-1)-(n-c);}
        else if(n>d&&n<=e){x=(-1)*m;y=m-(n-d);}
    }
    printf("(%d,%d)",x,y);
}
