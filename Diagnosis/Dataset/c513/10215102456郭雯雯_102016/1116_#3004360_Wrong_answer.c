#include<stdio.h>
#include<math.h>

int main(){
    int x,y,k;
    scanf("%d %d",&x,&y);
    int sum=abs(x)+abs(y);
    if(sum%2==0)k=-1;
    else{
        sum++;
        k=(int)log(sum)/log(2);
        double m=pow(2.0,k-1),n=pow(2.0,k);
        if(sum<=m||sum>n)k=-1;
    }
    printf("%d\n",k);
}