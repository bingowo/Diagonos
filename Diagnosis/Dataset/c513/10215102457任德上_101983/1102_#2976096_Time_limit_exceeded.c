#include<stdio.h>
#include<math.h>
long long int Sqrt(long long int a){
    long long int b=a/2LL;
    if(a<10000LL){
        b=(long long int)sqrt(a);
        return b;
    }

    while(!(b*b<=a&&(b+1)*(b+1)>a)){
        b=b/2+a/(2*b);
    }
    return b;
}

int main(){
    long long int a,b,x1,y1;
    scanf("%lld",&a);
    b=Sqrt(a);
    if(b%2LL==1LL){
        x1=(b-1LL)/2LL,y1=(b+1LL)/2LL;
        if(a-b*b<=b)x1=x1-(a-b*b);
        else if(a-b*b<=2*b+1){
            x1=x1-b;
            y1=y1-(a-b*b-b);
        }
    }
    else{
        x1=-b/2LL,y1=-b/2LL;
        if(a-b*b<=b)x1=x1+(a-b*b);
        else if(a-b*b<=2*b+1){
            x1=x1+b;
            y1=y1+(a-b*b-b);
        }
    }
    printf("(%d,%d)",x1,y1);
    return 0;
}
