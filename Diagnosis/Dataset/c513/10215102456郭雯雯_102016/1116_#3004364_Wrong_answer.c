#include<stdio.h>
#include<math.h>

int main(){
    long long x,y;
    scanf("%lld %lld",&x,&y);
    long long sum=abs(x)+abs(y);
    long long lg2[45];
    lg2[0]=1;
    for(int i=1;i<45;i++)lg2[i]=2*lg2[i-1];
    int k;
    if(sum%2==0)k=-1;
    else{
        sum++;
        for(int i=1;i<45;i++){
            if(sum<=lg2[i]&&sum>lg2[i-1])k=i;
        }
    }
    printf("%d\n",k);
}