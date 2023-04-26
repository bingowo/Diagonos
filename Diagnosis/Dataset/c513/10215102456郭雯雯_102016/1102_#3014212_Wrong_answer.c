#include<stdio.h>
#include<math.h>

int num(long long a){
    double m=(double)a/4;
    int b=(int)sqrt(m);
    double c=sqrt(m);
    if(c-b>0)b++;
    return b;
}

int main(){
    long long n;
    scanf("%lld",&n);
    int m=num(n),x,y;
    if(n==0){x=0;y=0;}
    else{
        long long a,b,c,d,e;
        b=(2*m-1)*(2*m-1);
        d=2*m*2*m;
        a=(2*m-1)*(2*m-2);
        c=(2*m-1)*(2*m);
        e=2*m*(2*m+1);
        if(n>=a&&n<b){x=m-1;y=(n-a)-m+1;}
        else if(n>=b&&n<c){y=m;x=(m-1)-(n-b);}
        else if(n>=c&&n<d){x=-1*m;y=m-(n-c);}
        else if(n>=d&&n<e){y=-1*m;x=y+(n-d);}
    }
    printf("(%d,%d)",x,y);
}
