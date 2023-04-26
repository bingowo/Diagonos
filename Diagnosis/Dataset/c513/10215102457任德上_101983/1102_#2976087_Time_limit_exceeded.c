#include<stdio.h>
long long int Sqrt(long long int a){
    long long int b=a/2LL;
    if(a==0LL)return 0LL;
    if(a==4LL)return 2LL;
    if(a==16LL)return 4LL;
    else if(a==1LL)return 1LL;
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
